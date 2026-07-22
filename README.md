# Arduino Passcode Security Lock System

An embedded access control system built with an Arduino Uno, a 4x4 matrix keypad, a 16x2 LCD display, and a servo-driven locking mechanism. Users enter a preset PIN code to unlock the door, with real-time feedback provided on the LCD display.

---

## Features

* **Passcode Validation:** Real-time processing of keypad inputs to match against stored security credentials.
* **Servo Lock Control:** Automated lock/unlock door mechanism triggered upon successful authentication.
* **Visual Status Display:** 16x2 LCD interface for status messages (e.g., *Access Granted*, *Wrong Password*).
* **Interactive Prototype:** Simulated and tested on TinkerCAD before physical hardware deployment.

---

## Hardware Components

* **Microcontroller:** Arduino Uno R3
* **Input:** 4x4 Matrix Keypad
* **Display:** 16x2 Liquid Crystal Display (LCD) & Potentiometer (for contrast adjustment)
* **Actuator:** Micro Servo Motor (SG90)
* **Misc:** Breadboard, 220Ω Resistor, jumper wires, external power supply

---

## Circuit Connections & Pinout

Since physical wiring layouts can get crowded, the table below outlines the exact pin connections used in this project:

### 4x4 Keypad
| Keypad Pin | Arduino Pin | Function |
| :--- | :--- | :--- |
| Row 1 - Row 4 | Digital Pins 2, 3, 4, 5 | Row Matrix Input |
| Col 1 - Col 4 | Digital Pins 6, 7, 8, 9 | Column Matrix Input |

### 16x2 LCD Display & Potentiometer
| LCD Pin | Connected To | Notes |
| :--- | :--- | :--- |
| VSS / VDD | GND / 5V | Logic Power |
| V0 | Potentiometer Center Pin | Contrast Control |
| RS, EN | Digital Pins 12, 11 | Register Select & Enable |
| D4, D5, D6, D7 | Digital Pins 5, 4, 3, 2 | 4-bit Data Interface |
| A / K (Backlight) | 5V (via Resistor) / GND | Display LED Power |

### Servo Motor
| Wire Color | Connection | Function |
| :--- | :--- | :--- |
| Orange / Yellow | Digital Pin 10 | PWM Control Signal |
| Red | 5V Rail | Power |
| Black / Brown | GND Rail | Common Ground |

---

## How to Set Up and Run

1. Clone or download this repository.
2. Open `security_system.ino` in the **Arduino IDE**.
3. Install the required standard libraries (`Keypad.h`, `LiquidCrystal.h`, `Servo.h`).
4. Connect your Arduino Uno via USB and select the correct Board and COM Port.
5. Upload the code to the board.

---
