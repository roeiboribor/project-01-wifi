#include "WiFiS3.h"

#include "src/services/Wifi/WiFiService.h"
#include "src/services/Supabase/SupabaseService.h"
#include "src/services/LEDMatrix/LEDMatrixService.h"

WiFiService wifiService;
SupabaseService supabaseService;
LEDMatrixService ledMatrixService;

void setup() {
  Serial.begin(115200); // initialize serial communication

  wifiService.initializeWifiService();
  supabaseService.initializeSupabaseService();

  // Initialize the LED matrix service
  ledMatrixService.initialize();
}

void loop() {
  // Code here...
}


