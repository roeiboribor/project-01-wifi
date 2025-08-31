#include "WiFiS3.h"

#include "src/services/Wifi/WiFiService.h"
#include "src/services/Supabase/SupabaseService.h"

int led =  LED_BUILTIN;

WiFiService wifiService;

void setup() {
  Serial.begin(115200); // initialize serial communication
  pinMode(led, OUTPUT); // set the LED pin mode

  wifiService.initializeWifiService();
  initializeSupabaseService();
}

void loop() {
  wifiService.handleClientRequests(led);
}
