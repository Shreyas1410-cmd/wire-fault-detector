# 🔍 Wire Fault Detection System using Hall Effect Sensor & Arduino

This project demonstrates a low-cost wire fault detection system using an analog Hall effect sensor and Arduino UNO. The goal was to detect anomalies like wire cuts inside a tube without removing insulation.

## 🚀 Project Features

- Detects magnetic field changes in live wires
- Identifies cuts via sudden magnetic field drops
- Fast blinking LED and buzzer alert upon detection
- Automatic reset mechanism after 10s
- Serial monitor warnings with values

## 🛠️ Hardware Used

- Arduino UNO
- Analog Hall Effect Sensor (3-pin: G, R, Y)
- Breadboard and jumper wires
- Buzzer
- 1k ohm Resistor
- External LED
- Power supply (USB or external battery)

## 📈 Version History & Learnings

| Version | Description | Key Learnings |
|--------|-------------|---------------|
| v1 | Basic sensor reading on Serial Monitor | How analog sensors behave |
| v2 | Added internal LED blinking | Debugging sensor values |
| v3 | Wire cut detection logic + reset | Conditional logic + smoothing |
| Final | Added buzzer, auto threshold, clean UI | Sensor stabilization, Arduino timing |

## 📷 Demo (Optional)

Add GIF or image of system working.

## 📎 Circuit Diagram

![Diagram](./final_version/diagram.png)

## 🧠 Problems Faced

- Serial monitor too fast to read ➜ Fixed using delay
- False triggers due to fluctuation ➜ Fixed using 3-value smoothing
- Couldn't upload to COM port ➜ Closed other apps using serial
- Buzzer not working ➜ Wrong pin / bad jumper ➜ fixed

## 🧑‍💻 Code Highlights

- Dynamic thresholding (no manual threshold)
- Time-based actions (non-blocking delays)
- Clean serial output for debugging

## 📋 Resume Description Sample

> Developed a fault-detection prototype using Hall-effect sensors and Arduino to identify anomalies in insulated wiring without physical contact. Implemented real-time serial monitoring, smoothing algorithms, auto-reset logic, and alert mechanisms. Published the evolving project on GitHub with version control and documentation of encountered challenges.

## 📁 How to Run

1. Connect Hall sensor:
   - G → GND
   - R → 5V
   - Y → A1

2. External LED to pin 7 with 1kΩ resistor

3. Buzzer to pin 8

4. Upload `hall_wire_fault_detector_final.ino`

5. Open Serial Monitor @9600 baud and slide sensor along wire tube

---

📌 For any queries or contributions, feel free to fork or raise an issue.
