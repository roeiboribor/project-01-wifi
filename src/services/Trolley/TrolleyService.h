#ifndef TROLLEY_SERVICE_H
#define TROLLEY_SERVICE_H

#include <Arduino.h>

// Define a struct to hold trolley data
struct Trolley {
    String trolley_name;
    int rows;
    int columns;
};

class TrolleyService {
public:
    TrolleyService();
    Trolley parseTrolleyData(const String& json);
};

#endif
