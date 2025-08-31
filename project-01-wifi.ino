#include "WiFiS3.h"

#include "src/services/Wifi/WiFiService.h"

int led =  LED_BUILTIN;

WiFiService wifiService(80);

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(led, OUTPUT); // set the LED pin mode

  wifiService.initializeWifiService();
}


void loop() {
  wifiService.handleClientRequests(led);
}
