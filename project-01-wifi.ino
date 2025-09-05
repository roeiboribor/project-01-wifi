#include "WiFiS3.h"

#include "src/services/Wifi/WiFiService.h"
#include "src/services/Supabase/SupabaseService.h"
#include "src/services/LEDMatrix/LEDMatrixService.h"
#include "src/services/Trolley/TrolleyService.h"

WiFiService wifiService;
LEDMatrixService ledMatrixService;
SupabaseService supabaseService;
TrolleyService trolleyService;

void setup() {
  Serial.begin(115200);

  wifiService.initializeWifiService();

  // Fetch and parse trolley data every 2 seconds
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

  // Initialize/Update LED matrix service with fetched data
  ledMatrixService.initialize(rows, columns); // This also calls turnOnGrid
}

void loop() {
  // Code Here...
}


