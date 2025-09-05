#include "WiFiS3.h"

#include "src/services/Wifi/WiFiService.h"
#include "src/services/Supabase/SupabaseService.h"

// include the LED Matrix library from the Uno R4 core:
#include "Arduino_LED_Matrix.h"
// #include "led_patterns.h" // Include our custom LED patterns
ArduinoLEDMatrix matrix;

// Define a 12x8 grid for the LED matrix
uint8_t my4x5Pattern[8][12]; // 8 rows, 12 columns

int led =  LED_BUILTIN;

WiFiService wifiService;
SupabaseService supabaseService;

void setup() {
  Serial.begin(115200); // initialize serial communication
  pinMode(led, OUTPUT); // set the LED pin mode

  wifiService.initializeWifiService();
  supabaseService.initializeSupabaseService();
  // start the matrix
  matrix.begin();
  
  // Initialize the pattern to all off
  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 12; c++) {
      my4x5Pattern[r][c] = 0;
    }
  }

  // Set the 4x5 region to ON (1)
  const int numRows = 4;
  const int numCols = 5;
  for (int r = 0; r < numRows; r++) {
    for (int c = 0; c < numCols; c++) {
      my4x5Pattern[r][c] = 1;
    }
  }

  // Render the bitmap to the LED matrix
  matrix.renderBitmap(my4x5Pattern, 8, 12);
}

void loop() {
  wifiService.handleClientRequests(led);
}


