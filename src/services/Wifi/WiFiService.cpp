#include "WiFiService.h"
#include <string.h> // For strcpy

WiFiService::WiFiService(int port) : _server(port) {
    strncpy(_ssid, SECRET_SSID, sizeof(_ssid) - 1);
    _ssid[sizeof(_ssid) - 1] = '\0';
    strncpy(_pass, SECRET_PASS, sizeof(_pass) - 1);
    _pass[sizeof(_pass) - 1] = '\0';
    _keyIndex = 0; // Assuming keyIndex is always 0 for now
}

void WiFiService::_checkWiFiModule() {
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }
}

void WiFiService::_checkFirmwareVersion() {
  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }
}

int WiFiService::_connectToWiFi(int currentStatus) {
  while (currentStatus != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(_ssid);
    currentStatus = WiFi.begin(_ssid, _pass);
    delay(10000);
  }
  return currentStatus;
}

void WiFiService::_printWifiStatus() {
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

int WiFiService::initializeWifiService() {
  _checkWiFiModule();
  _checkFirmwareVersion();
  int status = WL_IDLE_STATUS; 
  status = _connectToWiFi(status);
  _server.begin(); // Start the web server after connection
  _printWifiStatus();
}

void WiFiService::handleClientRequests(int ledPin) {
  WiFiClient client = _server.available();   

  if (client) {                             
    Serial.println("new client");           
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        if (c == '\n') {                    

          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> turn the LED on<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/L\">here</a> turn the LED off<br></p>");
            
            client.println();
            break;
          } else {    
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }

        if (currentLine.endsWith("GET /H")) {
          digitalWrite(ledPin, HIGH);               
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(ledPin, LOW);                
        }
      }
      
    }
    client.stop();
    Serial.println("client disconnected");
  }
}
