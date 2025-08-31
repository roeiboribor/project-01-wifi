#ifndef WiFiUtils_h
#define WiFiUtils_h

#include <Arduino.h>
#include <WiFiS3.h>

void checkWiFiModule();
void checkFirmwareVersion();
int connectToWiFi(char ssid[], char pass[], int currentStatus);
void printWifiStatus();
int initializeWifiService(char ssid[], char pass[]);

#endif
