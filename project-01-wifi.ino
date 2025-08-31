#include "WiFiS3.h"

#include "arduino_secrets.h" 
#include "src/Services/WiFiService.h"

int led =  LED_BUILTIN;
int status = WL_IDLE_STATUS;

WiFiService wifiService(80, SECRET_SSID, SECRET_PASS);

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(led, OUTPUT); // set the LED pin mode

  status = wifiService.initializeWifiService();
}


void loop() {
  wifiService.handleClientRequests(led);
}
