#include "TrolleyService.h"
#include <ArduinoJson.h>

TrolleyService::TrolleyService() {
    // Constructor
}

Trolley TrolleyService::parseTrolleyData(const String& json) {
    Trolley trolley;

    StaticJsonDocument<256> doc; // Adjust size as needed
    DeserializationError error = deserializeJson(doc, json);

    if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        // Return a default or empty Trolley object in case of error
        trolley.trolley_name = "";
        trolley.rows = 0;
        trolley.columns = 0;
        return trolley;
    }

    // Assuming the JSON is a single array with one object
    // For now, let's assume it's a single object directly
    if (doc.is<JsonArray>()) {
        JsonArray array = doc.as<JsonArray>();
        if (array.size() > 0) {
            JsonObject obj = array[0].as<JsonObject>();
            trolley.trolley_name = obj["trolley_name"].as<String>();
            trolley.rows = obj["rows"].as<int>();
            trolley.columns = obj["columns"].as<int>();
        }
    } else if (doc.is<JsonObject>()) {
        JsonObject obj = doc.as<JsonObject>();
        trolley.trolley_name = obj["trolley_name"].as<String>();
        trolley.rows = obj["rows"].as<int>();
        trolley.columns = obj["columns"].as<int>();
    }

    return trolley;
}
