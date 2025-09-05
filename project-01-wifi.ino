#include "WiFiS3.h"

#include "src/services/Wifi/WiFiService.h"
#include "src/services/Supabase/SupabaseService.h"
#include "src/services/LEDMatrix/LEDMatrixService.h"
#include "src/services/Trolley/TrolleyService.h"

WiFiService wifiService;
LEDMatrixService ledMatrixService;
SupabaseService supabaseService;
TrolleyService trolleyService;

int rows;
int columns;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  wifiService.initializeWifiService();

  // Fetch and parse trolley data every 2 seconds
  SupabaseResponse trolley = supabaseService.get("trollies", "select=trolley_name,rows,columns&limit=1");
  Trolley parsedTrolley = trolleyService.parseTrolleyData(trolley.responseBody);
  rows = parsedTrolley.rows;
  columns = parsedTrolley.columns;
  ledMatrixService.initialize(rows, columns); // Initialize the matrix
  ledMatrixService.turnOnGrid(rows, columns); // Turn it on initially
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  ledMatrixService.turnOffGrid(rows, columns);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  ledMatrixService.turnOnGrid(rows, columns);
  delay(1000);
}


