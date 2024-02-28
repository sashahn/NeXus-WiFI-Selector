
#include <NexusWiFiSelector.h>

NexusWiFiSelector nws;

void setup() {
  Serial.begin(115200);
  delay(100);
  nws.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // delay(1000);
  // digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));

}
