#ifndef NexusWiFiSelector_h
#define NexusWiFiSelector_h

#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include "SPIFFS.h"

class NexusWiFiSelector {
private:
  AsyncWebServer server;
  const char* ssidPlaceholder = "{{WIFI_NETWORKS}}";
  const char* SSIDPH = "{{SSIDPH}}";
  const char* IPPH = "{{IPPH}}";
  const char* PARAM_INPUT_1 = "ssid";
  const char* PARAM_INPUT_2 = "pass";
  const char* PARAM_INPUT_3 = "ip";
  const char* PARAM_INPUT_4 = "gateway";
  const char* ssidPath = "/ssid.txt";
  const char* passPath = "/pass.txt";
  const char* ipPath = "/ip.txt";
  const char* gatewayPath = "/gateway.txt";
  const long interval = 1000;
  int _ledPin;
  int _pinToControl;
  bool _debug;
  String ledState;
  String ssid;
  String pass;
  String ip;
  String gateway;
  IPAddress localIP;
  IPAddress localGateway;

public:
  NexusWiFiSelector();

  void begin(const int led_pin, const int pinToControl, const bool debug);

private:
  void initSPIFFS();
  String readFile(fs::FS& fs, const char* path);
  void writeFile(fs::FS& fs, const char* path, const char* message);
  bool initWiFi();
  String processor(const String& var);
  void setupWiFiServer();
  void setupAPServer();
  void handleRequest(AsyncWebServerRequest* request);
  void handleRequestWiFiManager(AsyncWebServerRequest* request);
  void handleRequestSuccess(AsyncWebServerRequest* request);
  void commonServerRouts();
};

#endif
