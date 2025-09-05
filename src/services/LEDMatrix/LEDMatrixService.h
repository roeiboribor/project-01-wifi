#ifndef LEDMatrixService_h
#define LEDMatrixService_h

#include <Arduino.h>
#include <Arduino_LED_Matrix.h>

class LEDMatrixService {
public:
    LEDMatrixService();
    void initialize(int rows, int columns);
    void turnOnGrid(int rows, int columns);
    void turnOffGrid(int rows, int columns);
    void setPixel(int row, int col, bool state);
    void updateDimensions(int newRows, int newColumns);

private:
    ArduinoLEDMatrix _matrix;
    uint8_t _displayGrid[8][12]; // Represents the 12x8 LED matrix
    int _numRows = 4;
    int _numCols = 5;
};

#endif
