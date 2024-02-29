<p><br/></p>

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
<p align="center">WiFi selector/manager library for wireless microcontrollers</p>
</br>
<p>USAGE: Install library to Arduino library folder. Open IDE and add.. </p>
<p align="center">
	<code>
		
#include <NexusWiFiSelector.h>  // Add lib

NexusWiFiSelector neXus;	// Create Object

void setup() {
  Serial.begin(115200);  
  delay(10);
  neXus.begin();		// Init it		
  pinMode(LED_BUILTIN, OUTPUT); // for visual debugging
}

void loop() {

  // do your stuff...

}

	</code>
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
<p align="center">
	NeXusWiFiSelector is evulation of <a href="https://randomnerdtutorials.com/esp32-wi-fi-manager-asyncwebserver/">a Wi-Fi Manager (AsyncWebServer library)</a>
</p>
"# NeXus-WiFI-Selector" 
# NeXus-WiFI-Selector
