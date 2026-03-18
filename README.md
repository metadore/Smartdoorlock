# 🛡️ Smart-Guard: The Dual-Auth Security Lock

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?color=00F7FF&center=true&vCenter=true&lines=Arduino+Smart+Security+System;Dual+Authentication+Lock;Touchless+Magic+Wave+Exit;Built+with+Innovation+🚀" />
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-Uno_R4-00979D?style=for-the-badge&logo=arduino&logoColor=white"/>
  <img src="https://img.shields.io/badge/Status-Active-00ffcc?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Security-High-red?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Build-Custom-blueviolet?style=for-the-badge"/>
</p>

---

## 🎥 Demo Video

<p align="center">
  👉 <b>Watch the project in action:</b> <br><br>
  🔗 https://www.instagram.com/reel/DV9DdTKApH0/?igsh=MTJsczM4aGdzODNlbw==
</p>

---

## 📸 Project Preview

<p align="center">
  <img src="https://github.com/metadore/Smartdoorlock/blob/main/WhatsApp%20Image%202026-03-18%20at%2010.41.37%20PM.jpeg" width="400"/>
  <img src="https://github.com/metadore/Smartdoorlock/blob/main/WhatsApp%20Image%202026-03-18%20at%2010.41.53%20PM.jpeg" width="400"/>
  <img src="https://github.com/metadore/Smartdoorlock/blob/main/WhatsApp%20Image%202026-03-18%20at%2010.41.54%20PM.jpeg" width="400"/>

</p>

---

## 🧠 Project Overview

> 🚀 **Smart-Guard** is a next-generation security system designed to eliminate unauthorized access using **dual authentication**.

### 🔐 Outside Access

* Secure PIN entry via Serial Monitor
* Default PIN: `1234`

### ✋ Inside Exit

* Touchless **Magic Wave System**
* Powered by Ultrasonic Sensor

### 🚨 Security Layer

* 3 wrong attempts → **Alarm Triggered**
* System Lockout → **30 seconds**
* Anti-tamper protection

---

## ✨ Features

* 🔐 Dual Authentication System
* 👋 Touchless Exit (Gesture Control)
* 📡 Real-time Distance Detection
* 🔊 Audio + Visual Feedback
* 🚨 Intrusion Alert System
* ⚡ Portable Power Support

---

## 🧩 Components Required

| 🔧 Category        | 📦 Component       |
| ------------------ | ------------------ |
| 🧠 Microcontroller | Arduino Uno R4     |
| 💪 Actuator        | SG90 Servo Motor   |
| 👁️ Sensor         | HC-SR04 Ultrasonic |
| 📟 Display         | 16x2 LCD (I2C)     |
| 🔲 Visual          | 8x8 LED Matrix     |
| 🔊 Audio           | Passive Buzzer     |
| 🔋 Power           | Powerbank          |
| 🔌 Wiring          | Jumper Wires       |

---

## 🔌 Wiring Guide

### 🔋 Power Setup

* Arduino **5V → Breadboard (+)**
* Arduino **GND → Breadboard (-)**

---

### 🔧 Pin Configuration

| Component       | Pin | Description   |
| --------------- | --- | ------------- |
| Ultrasonic Trig | 4   | Signal Out    |
| Ultrasonic Echo | 5   | Signal In     |
| Buzzer          | 8   | Audio Output  |
| Servo           | 9   | Motor Control |
| Matrix CS       | 10  | Chip Select   |
| Matrix DIN      | 12  | Data          |
| Matrix CLK      | 13  | Clock         |
| LCD SDA         | A4  | Data Line     |
| LCD SCL         | A5  | Clock Line    |

---

## 💻 Software Setup

### 📚 Install Libraries

Go to:
Arduino IDE → Sketch → Include Library → Manage Libraries

Install:

* LiquidCrystal I2C
* LedControl

---

### ⚙️ Upload Code

1. Open `.ino` file
2. Select Board:
   Tools → Arduino UNO R4
3. Click **Upload 🚀**

---

## 🕹️ How It Works

### 🔓 Unlock (Outside)

1. Connect via USB
2. Open Serial Monitor (9600 baud)
3. Enter PIN: `1234`

⚠️ 3 Wrong Attempts:

* Alarm 🚨
* 30-sec Lockout ⛔

---

### 🚪 Exit (Inside)

👋 Wave your hand (5–15 cm)

* Door opens automatically
* Welcome tone plays 🎵
* Auto closes after 5 sec

---

## 🧪 System Logic (Flow)

```text
START
 ↓
Wait for Input
 ↓
IF Outside → Check PIN
   ├── Correct → Unlock
   └── Wrong x3 → Alarm + Lockout
 ↓
IF Inside → Detect Hand Wave
 ↓
Unlock Door
 ↓
Auto Lock
```

---

## ⚠️ Troubleshooting

🔧 **LCD Blank?**
→ Adjust contrast knob

🔧 **Servo Not Moving?**
→ Use Powerbank

🔧 **Distance = 0?**
→ Check Trig/Echo wiring

---

## 📂 Project Structure

```
Smart-Guard/
 ├── SmartGuard.ino
 ├── README.md
 ├── assets/
 │    ├── images/
 │    └── videos/
```

---

## 🚀 Future Enhancements

* 📱 Mobile App Control
* 🔐 Fingerprint Module
* 🌐 IoT Integration
* ☁️ Cloud Logging
* 🔋 Battery Optimization

---

## 👨‍💻 Author

**metadore**

---

## 🌟 Support

If you like this project:

⭐ Star the repo
🍴 Fork it
🚀 Build your own version

---

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:00F7FF,100:8A2BE2&height=120&section=footer"/>
</p>

---

> 💡 *"Security is not a feature, it's a system."*
