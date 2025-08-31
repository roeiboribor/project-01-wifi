#include "WiFiS3.h"

#include "src/services/Wifi/WiFiService.h"
#include "src/services/Supabase/SupabaseService.h"

int led =  LED_BUILTIN;

WiFiService wifiService;
SupabaseService supabaseService;

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(led, OUTPUT); // set the LED pin mode

  wifiService.initializeWifiService();
  supabaseService.printAllSupabaseCredentials();
}

void loop() {
  wifiService.handleClientRequests(led);
}
