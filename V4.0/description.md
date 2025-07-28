# 🧠 Version 4.0 - Intelligent Wire Cut Detection (Auto-Learning)

v4.0 uses a dynamic and intelligent approach:
- Learns the baseline magnetic field at startup
- Detects anomalies based on rapid decrease, not fixed thresholds
- Adds a smarter way to prevent false positives

## 🚀 Features
- Automatic baseline detection (no need to manually adjust)
- Detects falling trend using a fallFactor (e.g. 85%)
- LED stays ON during alert, blinks otherwise
- Buzzer alerts user when anomaly occurs
- System resets after 10 seconds to resume monitoring

## 📌 Improvements over v3.0
- Removed hardcoded threshold
- Smarter decision-making based on actual readings

## 🛠 Setup
- Connect Hall Sensor OUT → A1
- Connect Buzzer (+) → D8, (-) → GND
- LED pin 13 used internally

## 📈 Logic
- Wait for buffer to fill → calculate baseline
- If `sensorValue < baseline * 0.85`, trigger alert
- Reset after 10 seconds, re-monitor

## 🔜 Next Goals
- Dynamic learning of baseline over time
- Real-time dashboard via serial/Bluetooth
- Voice or display-based alerts
