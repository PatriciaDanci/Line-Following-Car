# Line-Following and Obstacle-Avoiding Robot 🚗🤖

## 📌 Project Overview
This project is a **line-following robot** that uses **IR sensors** to detect and follow a black line. The robot is built using an **ESP32 microcontroller**, an **H-Bridge motor driver**, and **two DC motors** for movement. Additionally, it includes OTA (Over-the-Air) updates and Wi-Fi-based control for flexibility in programming.

## 🎯 Features
✔️ **Line Following** – Detects and follows a black line using IR sensors  
✔️ **Autonomous Turning** – Adjusts direction based on sensor input  
✔️ **180-Degree Turn** – When no line is detected, the robot turns back  
✔️ **Wi-Fi OTA Updates** – Allows wireless code uploads  
✔️ **Expandable Design** – Can be upgraded with obstacle avoidance  

## 🛠 Hardware Components
- **ESP32 (WROOM-32)**
- **H-Bridge Motor Driver (L298N)**
- **Two IR Sensors**
- **Two DC Motors**
- **6V Battery Pack**
- **Chassis with Wheels**
- **Breadboard and Connecting Wires**

## 📜 Circuit Connections
| **Component**  | **ESP32 GPIO Pin** |
|---------------|----------------|
| Left IR Sensor  | GPIO 33 |
| Right IR Sensor | GPIO 32 |
| Left Motor Forward | GPIO 27 |
| Left Motor Backward | GPIO 26 |
| Right Motor Forward | GPIO 13 |
| Right Motor Backward | GPIO 12 |

🔗 ***For the complete wiring diagram, check the `docs/` folder.***

## 🚀 Installation & Setup
### **1️⃣ Install Arduino IDE & ESP32 Board**
- Download **[Arduino IDE](https://www.arduino.cc/en/software)**
- Add ESP32 board support:
  - Go to **File > Preferences**
  - Add this URL: `https://dl.espressif.com/dl/package_esp32_index.json`
  - Install **ESP32 by Espressif Systems** from Board Manager

### **2️⃣ Required Libraries**
Before compiling, install the following libraries:
```bash
WiFi.h
ArduinoOTA.h
These are pre-installed with the ESP32 core.

3️⃣ Upload Code
Connect the ESP32 via USB.
Select the correct board: DOIT ESP32 DEVKIT V1
Select the right COM port in Tools > Port.
Upload the code to the board.
4️⃣ Enable OTA for Wireless Updates
First, upload the OTA sketch via USB.
Restart the ESP32, and it will now accept OTA uploads.
Upload future sketches wirelessly using the IP address printed in the Serial Monitor.
🎮 How It Works
The IR sensors detect black (LOW) and white (HIGH).
The robot follows the black line using simple logic:
Both sensors detect black → Move forward.
Left sensor detects black, right detects white → Turn left.
Right sensor detects black, left detects white → Turn right.
No sensors detect black → Stop or perform a 180° turn.
The Wi-Fi module allows for wireless programming and future expansion.
🔧 Troubleshooting
❌ ESP32 not detected in Arduino IDE?
✅ Check that the correct COM port is selected and install necessary drivers.

❌ Robot moves too fast?
✅ Implement PWM control to adjust motor speed.

❌ IR Sensors not detecting black line?
✅ Ensure sensors are properly calibrated and positioned close to the surface.

📌 Future Improvements
🔹 Add obstacle avoidance using ultrasonic sensors
🔹 Implement speed control via PWM
🔹 Integrate Bluetooth/Wi-Fi app for remote control
