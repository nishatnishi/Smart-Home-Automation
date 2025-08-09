# 🏠 Smart Home Automation using Arduino UNO

A simple yet powerful Smart Home Automation system built with Arduino UNO that combines **Password-Protected Door Lock** and **Voice-Controlled Light & Fan System** via Bluetooth.

---

## 📌 Project Overview
This project integrates two main features:
1. **Password Door Lock System** using a 4x4 keypad and servo motor.
2. **Voice-Controlled Appliances** (Light & Fan) using a Bluetooth module (HC-05) and relay control.

LCD display shows interactive messages for user guidance, such as:
- "Welcome Smart Home"
- "Enter Password"
- "Access Granted" / "Access Denied"
- Device control status: *Light ON*, *Light OFF*, *Fan ON*, *Fan OFF*

---

## ✨ Features
- Password-protected access to control door lock.
- Voice commands to control light and fan.
- LCD display for real-time feedback.
- Bluetooth connectivity for wireless control.
- Compact wiring with minimum components.
- Fully customizable password and voice commands.

---

## 🛠 Components Used
| Component | Quantity |
|-----------|----------|
| Arduino UNO | 1 |
| 4x4 Keypad | 1 |
| 16x2 LCD (with potentiometer) | 1 |
| HC-05 Bluetooth Module | 1 |
| Servo Motor (SG90/MG90) | 1 |
| Relay Module (2-channel) | 1 |
| LED (Light Indicator) | 2 |
| Resistors, Jumper Wires, Breadboard | - |
| External 5V Power Supply (for Servo) | 1 |

---

## 🔌 Circuit Diagram
![Circuit Diagram](circuit-diagram.png)  
*(Replace with your actual circuit image)*

**Key Wiring Overview:**
- **LCD**: RS → D12, EN → D11, D4-D7 → A3, A4, A5, D0, VSS → GND, VDD → 5V
- **Keypad (4x4)**: R1-R4 → D2-D5, C1-C4 → D6-D9
- **HC-05**: TX → D10, RX → D9 (via voltage divider), VCC → 5V, GND → GND
- **Servo**: Signal → D8, VCC → 5V External, GND Common
- **Relay**: IN1 → D7 (Light), IN2 → D6 (Fan), VCC → 5V, GND → GND

---

## 💻 Installation & Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/smart-home-automation.git
# Smart-Home-Automation
Password door lock &amp; voice control light fan on off.
