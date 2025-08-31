#include "WiFiUtils.h"

void checkWiFiModule() {
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }
}

void checkFirmwareVersion() {
  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }
}

int connectToWiFi(char ssid[], char pass[], int currentStatus) {
  while (currentStatus != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    currentStatus = WiFi.begin(ssid, pass);
    delay(10000);
  }
  return currentStatus;
}

void printWifiStatus() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}

int initializeWifiService(char ssid[], char pass[]) {
  checkWiFiModule();
  checkFirmwareVersion();
  int status = WL_IDLE_STATUS; // Initialize status here, as it's not a global in this file
  status = connectToWiFi(ssid, pass, status);
  printWifiStatus();
  return status;
}
