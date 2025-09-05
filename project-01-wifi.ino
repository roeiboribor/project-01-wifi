#include "WiFiS3.h"

#include "src/services/Wifi/WiFiService.h"
#include "src/services/Supabase/SupabaseService.h"
#include "src/services/LEDMatrix/LEDMatrixService.h"
#include "src/services/Trolley/TrolleyService.h"

WiFiService wifiService;
SupabaseService supabaseService;
LEDMatrixService ledMatrixService;
TrolleyService trolleyService;

void setup() {
  Serial.begin(115200); // initialize serial communication

  wifiService.initializeWifiService();

  // Example usage of the new generic get method
  SupabaseResponse locations = supabaseService.get("trolly_locations", "select=*&is_active=eq.true");
  Serial.println("Trolley Locations: ");
  Serial.println(locations.responseBody);
  Serial.println("Response code: " + String(locations.statusCode));

  SupabaseResponse trolley = supabaseService.get("trollies", "select=trolley_name,rows,columns&limit=1");
  Serial.println("Single Trolley: ");
  Serial.println(trolley.responseBody);
  
  Trolley parsedTrolley = trolleyService.parseTrolleyData(trolley.responseBody);

  const String trolley_name = parsedTrolley.trolley_name;
  const int rows = parsedTrolley.rows;
  const int columns = parsedTrolley.columns;
  
  Serial.println("Parsed Trolley Data:");
  Serial.print("  Name: ");
  Serial.println(trolley_name);
  Serial.print("  Rows: ");
  Serial.println(rows);
  Serial.print("  Columns: ");
  Serial.println(columns);
  
  Serial.println("Response code: " + String(trolley.statusCode));

  // Initialize the LED matrix service
  ledMatrixService.initialize(rows, columns);
}

void loop() {
}


