#include "NexusWiFiSelector.h"

/* 
* Primjena: NexusWiFiSelector ws;
* Namjena:  Kreira objekat...
* Tip:      Public
* Stranice u SPIFFS: index.html; landing.html; wifimanager.html; style.css
* Fajlovi/Stranice se ubacuju u SPIFFS preko ESP32_SPIFFS_FILE_UPLOADER-helper.ino (cuvaju su psram:const char indexHTML[] PROGMEM  
*                                                                                                   const char landing[] PROGMEM 
*                                                                                                   const char wifimanager[] PROGMEM
*                                                                                                   const char style[] PROGMEM )
* 
*/
NexusWiFiSelector::NexusWiFiSelector()
  : server(80) {}

/* 
* Primjena: ws.begin();
* Namjena:  Inicijalizuje zavisne komponente :
*           |Serial (ako vec nije .begin()) | SPIFFS init.. | popunjav promjenjlive sa podacima iz SPIFFS fajlova |
* Tip:      Public
*/
void NexusWiFiSelector::begin(int led_pin, int pinToControl, bool debug=false) {
  _ledPin = led_pin;
  _pinToControl = pinToControl;
  _debug = debug;
  // Serial port for debugging purposes
  if (!Serial) {
   if(_debug)Serial.begin(115200);
    delay(100);
   if(_debug)Serial.println("Init Serial comm...");
  } else {
   if(_debug)Serial.println("Serial comm started...");
  }
  server.serveStatic("/", SPIFFS, "/");
  initSPIFFS();
  pinMode(_ledPin, OUTPUT);
  pinMode(_pinToControl, OUTPUT);
  digitalWrite(_ledPin, LOW);
  ssid = readFile(SPIFFS, ssidPath);
  pass = readFile(SPIFFS, passPath);
  ip = readFile(SPIFFS, ipPath);
  gateway = readFile(SPIFFS, gatewayPath);
 if(_debug)Serial.println(ssid);
 if(_debug)Serial.println(pass);
 if(_debug)Serial.println(ip);
 if(_debug)Serial.println(gateway);

  if (initWiFi()) {
    setupWiFiServer();
  } else {
    setupAPServer();
  }
}

/* 
* Primjena: initSPIFFS();
* Namjena:  Inicijalizuje SPIFFS...
* Tip:      Private
*/
void NexusWiFiSelector::initSPIFFS() {
  if (!SPIFFS.begin(true)) {
   if(_debug)Serial.println("An error has occurred while mounting SPIFFS");
  }
 if(_debug)Serial.println("SPIFFS mounted successfully");
}

/* 
* Primjena: readFile(SPIFFS, "/nekiFajl.txt|html|itd..."); u begin(); i  metodi
* Namjena:  Vraca String podatak iz SPIFFS fajla...
* Tip:      Private
*/
String NexusWiFiSelector::readFile(fs::FS& fs, const char* path) {
 if(_debug)Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path);
  if (!file || file.isDirectory()) {
   if(_debug)Serial.println("- failed to open file for reading");
    return String();
  }

  String fileContent;
  while (file.available()) {
    fileContent = file.readStringUntil('\n');
    break;
  }
 if(_debug)Serial.println(fileContent);

  return fileContent;
}

/* 
* Primjena: writeFile(SPIFFS, "/nekiFajl.txt|html|itd...", "Sadrzaj fajla..."); u begin(); metodi
* Namjena:  Vraca String podatak iz SPIFFS fajla...
* Tip:      Private
*/
void NexusWiFiSelector::writeFile(fs::FS& fs, const char* path, const char* message) {
 if(_debug)Serial.printf("Writing file: %s\r\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file) {
   if(_debug)Serial.println("- failed to open file for writing");
    return;
  }
  if (file.print(message)) {
   if(_debug)Serial.println("- file written");
  } else {
   if(_debug)Serial.println("- write failed");
  }
}

/* 
* Primjena: initWiFi();
* Namjena:  Koristi se u .begin() metod. Hendluje sve vezano za WiFi konekciju i kaci se na mrezu ako u bazi postoje parametri i vraca True, 
*           ako ne, vraca False...
* Tip:      Private
*/
bool NexusWiFiSelector::initWiFi() {
  if (ssid == "" || ip == "") {
   if(_debug)Serial.println("Undefined SSID or IP address.");
    return false;
  }

  WiFi.mode(WIFI_STA);
  /*WiFi.setTxPower(WIFI_POWER_7dBm); // NeXus Hera has amazing results with minimal tx power too...*/

  localIP.fromString(ip.c_str());
  localGateway.fromString(gateway.c_str());

  if (!WiFi.config(localIP, localGateway, IPAddress(255, 255, 0, 0))) {
   if(_debug)Serial.println("STA Failed to configure");
    return false;
  }
  WiFi.begin(ssid.c_str(), pass.c_str());


  unsigned long currentMillis = millis();
  unsigned long previousMillis = currentMillis;


  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(_ledPin, HIGH);  // Connecting turn ON Led...
    currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      // if (WiFi.status() == 1 || WiFi.status() == 6) {
      //   //WiFi.disconnect();
      //  if(_debug)Serial.println("NO AP found, correcting files...");
      //   writeFile(SPIFFS, ssidPath, "\n");
      //   writeFile(SPIFFS, passPath, "\n");
      //   writeFile(SPIFFS, ipPath, "\n");
      //   writeFile(SPIFFS, gatewayPath, "\n");
      //   delay(3000);
      //   ESP.restart();
      // }
     if(_debug)Serial.println("Failed to connect.");
      return false;
    }
  }
 if(_debug)Serial.println(WiFi.localIP());
  digitalWrite(_ledPin, LOW);  // Connected turn Off Led...
  return true;
}

/* 
* Primjena: processor(var); // Korisit se samo u HTTP_GET server request hndlerima..
* Namjena:  hendluje request vezan za GPIO 7(LED_BUILTIN) i vraca stranici podatak ON ili OFF...
* Tip:      Private
*/
String NexusWiFiSelector::processor(const String& var) {
  if (var == "STATE") {
    if (digitalRead(_ledPin)) {
      ledState = "ON";
    } else {
      ledState = "OFF";
    }
    return ledState;
  }
  return String();
}

void NexusWiFiSelector::commonServerRouts() {
  server.on("/picker", HTTP_POST, [&](AsyncWebServerRequest* request) {
    handleRequest(request);
  });

  server.on("/scan", HTTP_GET, [&](AsyncWebServerRequest* request) {
    handleRequestWiFiManager(request);
  });

  server.on("/success", HTTP_GET, [&](AsyncWebServerRequest* request) {
    ESP.restart();
  });
}

/* 
* Primjena: setupWiFiServer(); 
* Namjena:  Koristi se u .begin() metodi ako su parametri WiFi mreze definisani, startuje server i | /Index.html za kontrolu led GPIO7...
* Tip:      Private
*/
void NexusWiFiSelector::setupWiFiServer() {
  server.end();

  server.on("/", HTTP_GET, [&](AsyncWebServerRequest* request) {
    request->send(SPIFFS, "/index.html", "text/html", false, std::bind(&NexusWiFiSelector::processor, this, std::placeholders::_1));
  });

  server.on("/on", HTTP_GET, [&](AsyncWebServerRequest* request) {
    digitalWrite(_pinToControl, HIGH);
    request->send(SPIFFS, "/index.html", "text/html", false, std::bind(&NexusWiFiSelector::processor, this, std::placeholders::_1));
  });

  server.on("/off", HTTP_GET, [&](AsyncWebServerRequest* request) {
    digitalWrite(_pinToControl, LOW);
    request->send(SPIFFS, "/index.html", "text/html", false, std::bind(&NexusWiFiSelector::processor, this, std::placeholders::_1));
  });

  this->commonServerRouts();

  server.begin();
}

/* 
* Primjena: setupAPServer();
* Namjena:  Koristi se u .begin() metodi ako parametri WiFi mreze nisu definisani, startuje WiFi Selector  landing page| /landing.html...
* Tip:      Private
*/
void NexusWiFiSelector::setupAPServer() {

  server.end();

 if(_debug)Serial.println("Setting AP (Access Point)");
  // NULL sets an open Access Point
  WiFi.softAP("NeXus-WiFi", NULL);
 /*WiFi.setTxPower(WIFI_POWER_7dBm); // NeXus Hera has amazing results with minimal tx power too...*/

  IPAddress IP = WiFi.softAPIP();
 if(_debug)Serial.print("AP IP address: ");
 if(_debug)Serial.println(IP);

  server.on("/", HTTP_GET, [&](AsyncWebServerRequest* request) {
    request->send(SPIFFS, "/landing.html", "text/html");
  });

  this->commonServerRouts();

  server.begin();
}

/* 
* Primjena: handleRequest(*request); 
* Namjena:  Koristi se u setupAPServer() | setupWiFiServer() metodama. Dobijene parametre (SSID,Pass,Ip,Getaway) upisuje u SPIFFS fajlove
*           uzvraca potvrdom preko request->send(200,...) i restartuje MCU.
* Tip:      Private
*/
void NexusWiFiSelector::handleRequest(AsyncWebServerRequest* request) {
  int params = request->params();
  for (int i = 0; i < params; i++) {
    AsyncWebParameter* p = request->getParam(i);
    if (p->isPost()) {
      if (p->name() == PARAM_INPUT_1) {
        ssid = p->value().c_str();
       if(_debug)Serial.print("SSID set to: ");
       if(_debug)Serial.println(ssid);
        writeFile(SPIFFS, ssidPath, ssid.c_str());
      } else if (p->name() == PARAM_INPUT_2) {
        pass = p->value().c_str();
       if(_debug)Serial.print("Password set to: ");
       if(_debug)Serial.println(pass);
        writeFile(SPIFFS, passPath, pass.c_str());
      } else if (p->name() == PARAM_INPUT_3) {
        ip = p->value().c_str();
       if(_debug)Serial.print("IP Address set to: ");
       if(_debug)Serial.println(ip);
        writeFile(SPIFFS, ipPath, ip.c_str());
      } else if (p->name() == PARAM_INPUT_4) {
        gateway = p->value().c_str();
       if(_debug)Serial.print("Gateway set to: ");
       if(_debug)Serial.println(gateway);
        writeFile(SPIFFS, gatewayPath, gateway.c_str());
      }
    }
  }
  handleRequestSuccess(request);
}

/* 
* Primjena: handleRequestWiFiManager(*request);
* Namjena:  Koristi se u .setupAPServer() | setupWiFiServer() metodama. Skenira dostupne wifi mreze, pakuje ih u listu, edituje
*           wifimanager.html tako sto u placeholder implementira listu mreza i servira /wifimanager.html...
*           Vzuelna signalizacija: na pokretanju WiFi.scanNetworks() LED je ON i po zavrsetku OFF...
* Tip:      Private
*/
void NexusWiFiSelector::handleRequestWiFiManager(AsyncWebServerRequest* request) {
  digitalWrite(_ledPin, HIGH);
  int numNetworks = WiFi.scanNetworks();

  String networksHTML = "<option hidden value=\"\">Networks</option>";
  if (numNetworks == 0) {
    networksHTML = "<option disabled value=\"\" disabled>No networks found</option>";
  } else {
    for (int i = 0; i < numNetworks; i++) {
      networksHTML += "<option value=\"" + WiFi.SSID(i) + "\">" + WiFi.SSID(i) + " <small>(" + WiFi.RSSI(i) + ")</small</option>";
    }
  }

  WiFi.scanDelete();

  File file = SPIFFS.open("/wifimanager.html", "r");
  if (file) {
    String htmlContent = file.readString();
    htmlContent.replace(ssidPlaceholder, networksHTML);
    request->send(200, "text/html", htmlContent);
    file.close();
  } else {
    request->send(404);
  }

  digitalWrite(_ledPin, LOW);
}

/* 
* Primjena: handleRequestSuccess(*request);
* Namjena:  Koristi se u .handleRequest() | Success stranica koju salje wifimanager.html po upisu SSID,PASS,IP itd... u SPIFFS....
* Tip:      Private
*/
void NexusWiFiSelector::handleRequestSuccess(AsyncWebServerRequest* request) {
  digitalWrite(_ledPin, HIGH);

  File file = SPIFFS.open("/success.html", "r");
  if (file) {
    String ssidPH = ssid.c_str();
    String ipPH = ip.c_str();
    String htmlContent = file.readString();
    htmlContent.replace(SSIDPH, ssidPH);
    htmlContent.replace(IPPH, ipPH);
    request->send(200, "text/html", htmlContent);
    file.close();
   if(_debug)Serial.println("OK from requstSuccess...");
  } else {
   if(_debug)Serial.println("ERROR from requstSuccess...");
    request->send(404);
  }
  digitalWrite(_ledPin, LOW);
}
