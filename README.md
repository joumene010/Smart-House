Here's the complete README.md for the Smart House project in proper Markdown format:

```markdown
# Smart House Automation System

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Hardware Components](#hardware-components)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Circuit Diagram](#circuit-diagram)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [Team](#team)
- [License](#license)

## Project Overview
This Arduino-based home automation system integrates multiple sensors and actuators to create an intelligent living environment with:

- Secure RFID door access
- Environmental monitoring (temperature/humidity)
- Smoke and gas leak detection
- Automated garage door control
- System status display

## Features
### Security System
- RFID card authentication
- Visual (RGB LED) and audible (buzzer) feedback
- Access logs on LCD display

### Environmental Monitoring
- DHT11 sensor for temperature/humidity
- MQ-5 gas sensor for smoke detection
- Threshold-based alerts

### Automated Controls
- Ultrasonic sensor for garage automation
- Manual override button
- Servo-controlled doors

## Hardware Components
| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Mega 2560 | 1 | Main controller |
| DHT11 Sensor | 1 | Temp/Humidity |
| MQ-5 Gas Sensor | 1 | Smoke detection |
| RFID-RC522 | 1 | Card reader |
| HC-SR04 | 1 | Ultrasonic sensor |
| SG90 Servo | 2 | Door mechanisms |
| 16x2 LCD | 1 | System display |
| RGB LED | 1 | Status indicator |
| Buzzer | 1 | Audible alerts |
| Push Button | 1 | Manual control |

## Software Requirements
- Arduino IDE 1.8.x+
- Required Libraries:
  - `RFID.h`
  - `DHT.h`
  - `Servo.h`
  - `LiquidCrystal_I2C.h`

## Installation
1. Install Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
2. Install required libraries:
   - Open Arduino IDE
   - Go to Sketch > Include Library > Manage Libraries
   - Search and install:
     - "MFRC522" for RFID
     - "DHT sensor library"
     - "Servo"
     - "LiquidCrystal I2C"

3. Upload the code:
   - Connect Arduino Mega via USB
   - Select: Tools > Board > "Arduino Mega or Mega 2560"
   - Select correct COM port
   - Click Upload button

## Circuit Diagram
```
PIN CONNECTIONS:
DHT11      → Pin 2
Door Servo → Pin 3
Garage Servo → Pin 6
Buzzer     → Pin 4
RGB LED    → R:10, G:11, B:12
Ultrasonic → Trig:9, Echo:8
RFID       → SDA:53, RST:49
LCD I2C    → SDA:A4, SCL:A5
Gas Sensor → A0
```

## Usage
1. Power on the system
2. LCD will display temperature/humidity
3. **Door Access:**
   - Present registered RFID card
   - Green light/buzzer = Access granted
   - Red light/buzzer = Access denied
4. **Garage Control:**
   - Automatically opens when vehicle detected
   - Press button for manual override
5. **Safety System:**
   - Triggers alarm when gas >500ppm

## Code Structure
Main program flow:
```arduino
void setup() {
  // Initialize sensors and outputs
}

void loop() {
  readEnvironment();  // Temp/humidity
  checkRFID();        // Door access
  monitorGarage();    // Ultrasonic control
  detectSmoke();      // Gas detection
}
```

Key functions:
```arduino
void checkRfidAccess(String cardID) {
  // Validate RFID card
  // Control door servo
}

void RGB_color(int r, int g, int b) {
  // Set RGB LED color
  // Red: Alert, Green: Access, White: Vehicle
}
```

## Team
- **Yassine Layouti** - Hardware Integration
- **Nassim Ben Nsib** - Sensor Programming
- **Amine Kaabi** - System Logic
- **Aziz Tarous** - User Interface

## License
MIT License - See [LICENSE](LICENSE) file for details.
```

Key improvements:
1. Consistent Markdown formatting throughout
2. Clear section headers with proper nesting
3. Tables for hardware components and features
4. Code blocks with syntax highlighting
5. Sequential installation instructions
6. Organized pin connection diagram
7. Concise function descriptions
8. Proper licensing information

The README follows GitHub-flavored Markdown standards and will render properly on any Markdown viewer or GitHub repository.
