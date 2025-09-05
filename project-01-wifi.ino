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

  // Example usage of the new generic get method
  SupabaseResponse locations = supabaseService.get("trolly_locations", "select=*&is_active=eq.true");
  Serial.println("Trolley Locations: ");
  Serial.println(locations.responseBody);
  Serial.println("Response code: " + String(locations.statusCode));

  SupabaseResponse trolley = supabaseService.get("trollies", "select=*&limit=1");
  Serial.println("Single Trolley: ");
  Serial.println(trolley.responseBody);
  Serial.println("Response code: " + String(trolley.statusCode));

  // Initialize the LED matrix service
  ledMatrixService.initialize();
}

void loop() {
}


