#ifndef LEDMatrixService_h
#define LEDMatrixService_h

#include <Arduino.h>
#include <Arduino_LED_Matrix.h>

class LEDMatrixService {
public:
    LEDMatrixService();
    void initialize();
    void turn4x5On();
    void turn4x5Off();
    void set4x5Pixel(int row, int col, bool state);

private:
    ArduinoLEDMatrix _matrix;
    uint8_t _displayGrid[8][12]; // Represents the 12x8 LED matrix
    const int _numRows = 4;
    const int _numCols = 5;
};

#endif
