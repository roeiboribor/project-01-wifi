#ifndef WiFiService_h
#define WiFiService_h

#include "../../../env.h"

#include <Arduino.h>
#include "WiFiS3.h"

class WiFiService {
public:
    WiFiService();
    int initializeWifiService();
    void handleClientRequests(int ledPin);

private:
    WiFiServer _server;
    char _ssid[32];
    char _pass[64];
    int _keyIndex;
    
    void _checkWiFiModule();
    void _checkFirmwareVersion();
    int _connectToWiFi(int currentStatus);
    void _printWifiStatus();
};

#endif
