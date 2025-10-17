# Car Reverse Parking Assistant

An Arduino-based prototype to assist drivers while reversing by detecting obstacles behind the vehicle. The system provides **visual (LEDs)** and **audible (buzzer)** alerts along with **real-time distance updates on a 16x2 LCD**.

---

## 🚗 Features

- Detects obstacles using **HC-SR04 Ultrasonic Sensor**  
- Displays distance and status on a **16x2 LCD**:
  - `SAFE` → distance > 20 cm  
  - `NEARBY` → 10 cm < distance ≤ 20 cm (Yellow LED ON)  
  - `VERY CLOSE` → distance ≤ 10 cm (Red LED + Buzzer ON)  
- Provides visual alerts with LEDs  
- Provides audible alert with buzzer  
- Real-time updates for safe and precise parking

---

## 🛠 Components Required

- Arduino Uno  
- HC-SR04 Ultrasonic Sensor  
- 16x2 LCD Display (I2C)  
- Yellow LED  
- Red LED  
- Buzzer  
- Jumper wires and breadboard  

---

## 🔌 Circuit Connections

| Component       | Arduino Pin |
|-----------------|-------------|
| TRIG (HC-SR04)  | 9           |
| ECHO (HC-SR04)  | 10          |
| Yellow LED      | 6           |
| Red LED         | 7           |
| Buzzer          | 8           |
| LCD SDA         | A4          |
| LCD SCL         | A5          |

*(Optional: Add a circuit diagram or image here)*

---

## 💻 Installation / Upload

1. Clone the repository:

```bash
git clone https://github.com/sandu10/Car-Reverse-Parking-Assistant.git
