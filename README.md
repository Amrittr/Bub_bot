# 🤖 Bubbot – Smart Desktop Companion Robot

## 📌 Project Overview

**Bubbot** is a small interactive desktop robot built using the **Seeed Studio ESP32-C3**, an **OLED display**, and a **touch sensor**. The robot displays animated facial expressions, reacts to touch input, connects to WiFi, and shows real-time clock and date information.

This project is designed for beginners who want to learn:

* ESP32 programming
* OLED display interfacing
* Touch sensor interaction
* WiFi connectivity
* Real-time clock using internet time
* Simple animations and mood systems

Bubbot acts like a tiny emotional desk companion that makes your workspace more interactive and fun.

---

## 🌟 Features of Bubbot

✅ Animated blinking eyes  
✅ Multiple moods and expressions  
✅ Touch interaction  
✅ Single tap to change mood  
✅ Double tap to show real time and date  
✅ Long touch/rub animation  
✅ WiFi connection  
✅ OLED display output  
✅ Beginner-friendly code structure  

---

## 🧠 Working Principle

Bubbot works using three main components:

1. **ESP32-C3** → Main controller
2. **OLED Display** → Shows robot face and time
3. **Touch Sensor** → Detects user interaction

The ESP32 continuously:
* Reads touch sensor input
* Changes robot mood
* Animates the face
* Fetches time from WiFi
* Displays everything on OLED

---

## 🧩 Components Required

| Component                         | Quantity |
| --------------------------------- | -------- |
| Seeed Studio ESP32-C3             | 1        |
| OLED Display (SSD1306 I2C 128x64) | 1        |
| Touch Sensor (TTP223)             | 1        |
| Breadboard                        | 1        |
| Jumper Wires                      | Few      |
| USB Cable                         | 1        |
| Laptop/PC with Arduino IDE        | 1        |

---

## 🔌 Circuit Connections

### OLED Display Connections

| OLED Pin | ESP32-C3 Pin |
| -------- | ------------ |
| VCC      | 3.3V         |
| GND      | GND          |
| SDA      | D4           |
| SCL/SCK  | D5           |

### Touch Sensor Connections

| Touch Sensor Pin | ESP32-C3 Pin |
| ---------------- | ------------ |
| VCC              | 3.3V         |
| GND              | GND          |
| OUT              | D6           |

---

## 🛠️ Software Required

### Install Arduino IDE
Download: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

### Install ESP32 Board
1. Open Arduino IDE
2. Go to: `File → Preferences`
3. Paste this URL inside “Additional Board Manager URLs”:
   ```text
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Click OK
5. Go to: `Tools → Board → Boards Manager`
6. Search: `ESP32`
7. Install ESP32 package

---

## 📚 Required Libraries

Install these libraries using: `Sketch → Include Library → Manage Libraries`

1. **Adafruit GFX Library**: Used for drawing shapes and graphics.
2. **Adafruit SSD1306**: Used for controlling OLED display.
3. **Adafruit BusIO**: Dependency library.

---

## ⚙️ Selecting the Board

Go to: `Tools → Board`
Select: `ESP32C3 Dev Module`

---

## 🤖 Code Structure

The source code is provided in the `Bubbot/` directory. Simply open `Bubbot.ino` in your Arduino IDE, configure your WiFi credentials, select the correct COM port, and upload.

---

## ▶️ How to Upload the Code

1. Connect ESP32-C3 using USB cable
2. Open Arduino IDE
3. Open `Bubbot/Bubbot.ino`
4. Update `ssid` and `password` with your WiFi credentials
5. Select correct COM port (`Tools → Port`)
6. Click Upload

---

## 🖥️ Serial Monitor Output

Open: `Tools → Serial Monitor`
Set baud rate: `115200`

You will see messages like:
```text
Starting Bubbot...
OLED connected
Connecting to WiFi...
WiFi Connected!
Time synced from NTP
Touch detected
Mood: Happy
Blink
```

---

## 🔥 Future Improvements

You can upgrade Bubbot by adding:
- [ ] Battery monitoring
- [ ] Voice assistant
- [ ] Telegram notifications
- [ ] Speaker and sound effects
- [ ] Servo motors for movement
- [ ] AI chatbot system
- [ ] Mobile app control
- [ ] Weather display
- [ ] Bluetooth connectivity

---

## 📌 Advantages of the Project

* Beginner-friendly & low-cost hardware
* Interactive and fun
* Good for learning IoT & improves coding skills
* Real product-style project

---

## 🎯 Applications

* Smart desk companion
* Educational robot
* IoT learning project
* Fun desktop gadget
* Emotional interaction bot

---

## 🏁 Conclusion

Bubbot is a beginner-friendly smart desktop robot that combines animation, touch interaction, WiFi communication, and real-time information display using ESP32-C3 and OLED technology. This project helps students understand embedded systems, IoT, and interactive electronics in a simple and creative way.

Demonstrating how small hardware components can be combined to create an emotional and intelligent robotic companion.

---

# 🏷️ Bubbot
**"Your tiny desk buddy."**
