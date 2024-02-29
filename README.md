<p><br/></p>
<p align="center">WiFi selector/manager lightwait library for wireless microcontrollers</p>
</br>
<br/>
<p align="center">
<img src="/docs/IMG_1.jpeg" width="100">
&nbsp;
<img src="/docs/IMG_2.jpeg" width="100">
&nbsp;
<img src="/docs/IMG_3.jpeg" width="100">
&nbsp;
<img src="/docs/IMG_4.jpeg" width="100">
&nbsp;
<img src="/docs/IMG_36.jpeg" width="100">
</p>
<br/>

<p>USAGE:</br>	

```
	STEP 1:
	1.1 Open file: ESP_SPIFFS_FILE-UPLOADER-HELPER.ino.
	1.2 Edit HTML templates |indexHTML |landing |scan | wifimanager | style | to acommodate your needs 
	1.3 Uplad it to the chip and run it once. HTML files will be stored in SPIFFS
	STEP 2:
	2.1 From example menu open: NeXusWiFiSelector.ino.
	Happy coding
```

``` C++
	#include "NexusWiFiSelector.h"

	#define DEBUGG true
	cons int pinToControl = 7;
	
	NexusWiFiSelector ws;
	
	void setup() {
	  Serial.begin(115200);
	  delay(100);
	  ws.begin(LED_BUILTIN, pinToControl, DEBUGG);  //.begin(pin for visual debug, on/off pin, Serial debug);
	}
			
	void loop() {
			
		// do your stuff...
			
	} 	
	
```
</p>

<br/>
<br/>

## Features
- 🔥 Wi-Fi Manager with the ESPAsyncWebServer
- 🏀 allows you to connect the ESP32 board to different Access Points (networks) without hard-coding network credentials
- 🎷 Your ESP will automatically join the last saved network or set up an Access Point that you can use to configure the network credentials
- 🛫 Ready to use within 2 line of code 

<br/>

## Supported MCUs
NeXusWiFiSelector works on the following microcontrollers/boards:
- ESP8266
- ESP32

<br/>
<br/>
<p>
	NeXusWiFiSelector is evulation of <a href="https://randomnerdtutorials.com/esp32-wi-fi-manager-asyncwebserver/">a Wi-Fi Manager (AsyncWebServer library)</a>
</p>
"# NeXus-WiFI-Selector" 
"# WiFI Selector" "# NeXus WiFI Manager"
