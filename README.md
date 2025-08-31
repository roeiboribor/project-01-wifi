# Project-01-WiFi

This project demonstrates how to connect an Arduino R4 WiFi board to WiFi.

## Project Structure

The project follows a modular structure to keep the code organized:

-   `project-01-wifi.ino`: The main Arduino sketch.
-   `env.h`: Contains sensitive environment variables like WiFi credentials. (Always keep `env.example.h` for version control and copy it to `env.h` for local development.)
-   `src/`: This directory is crucial for the Arduino IDE. All custom `.cpp` and `.h` files for services and modules **must** be placed within subdirectories of `src` for them to be compiled correctly by the Arduino IDE.
    -   Example: Create subdirectories like `src/services/Wifi/` for WiFi-related code, or `src/services/ExampleService/` for a generic service example.
    -   Organize your files logically within these subdirectories to maintain a clean and maintainable codebase.

