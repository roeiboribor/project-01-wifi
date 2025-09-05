#include "LEDMatrixService.h"

LEDMatrixService::LEDMatrixService() {
    // Initialize the display grid to all off
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 12; c++) {
            _displayGrid[r][c] = 0;
        }
    }
}

void LEDMatrixService::initialize() {
    _matrix.begin();
    Serial.println("LEDMatrixService initialized.");
    turn4x5On(); // Turn on the 4x5 region by default
}

void LEDMatrixService::turn4x5On() {
    for (int r = 0; r < _numRows; r++) {
        for (int c = 0; c < _numCols; c++) {
            _displayGrid[r][c] = 1; // Set to ON
        }
    }
    _matrix.renderBitmap(_displayGrid, 8, 12);
    Serial.println("4x5 LED region ON.");
}

void LEDMatrixService::turn4x5Off() {
    for (int r = 0; r < _numRows; r++) {
        for (int c = 0; c < _numCols; c++) {
            _displayGrid[r][c] = 0; // Set to OFF
        }
    }
    _matrix.renderBitmap(_displayGrid, 8, 12);
    Serial.println("4x5 LED region OFF.");
}

void LEDMatrixService::set4x5Pixel(int row, int col, bool state) {
    if (row >= 0 && row < _numRows && col >= 0 && col < _numCols) {
        _displayGrid[row][col] = state ? 1 : 0;
        _matrix.renderBitmap(_displayGrid, 8, 12);
        Serial.print("Setting 4x5 LED at (");
        Serial.print(row);
        Serial.print(", ");
        Serial.print(col);
        Serial.print(") to ");
        Serial.println(state ? "ON" : "OFF");
    } else {
        Serial.println("Error: Pixel coordinates out of 4x5 bounds.");
    }
}
