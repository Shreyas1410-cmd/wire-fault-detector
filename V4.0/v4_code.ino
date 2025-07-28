// v4.0 - Auto-baseline detection & rapid-fall alert system

const int hallPin = A1;
const int ledPin = 13;
const int buzzerPin = 8;

const int smoothCount = 5;
const float fallFactor = 0.85; // If value falls below 85% of baseline

int readings[smoothCount];
int index = 0;
float baseline = 0;

bool baselineReady = false;
bool cutDetected = false;
unsigned long cutTime = 0;
unsigned long resetDelay = 10000;
unsigned long lastBeepTime = 0;
bool buzzerState = false;

void setup() {
  pinMode(hallPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("📡 v4.0 - Auto-learning baseline and monitoring...");
}

void loop() {
  int sensorValue = analogRead(hallPin);

  readings[index] = sensorValue;
  index = (index + 1) % smoothCount;

  // Wait until buffer is full to compute baseline
  if (!baselineReady && index == 0) {
    int sum = 0;
    for (int i = 0; i < smoothCount; i++) {
      sum += readings[i];
    }
    baseline = sum / (float)smoothCount;
    baselineReady = true;
    Serial.print("📊 Baseline set to: ");
    Serial.println(baseline);
  }

  if (baselineReady) {
    Serial.print("Magnetic Field: ");
    Serial.print(sensorValue);
    Serial.print(" | Baseline: ");
    Serial.println(baseline);

    if (!cutDetected && sensorValue < baseline * fallFactor) {
      cutDetected = true;
      cutTime = millis();
      Serial.println("⚠️ ALERT: Wire anomaly detected (rapid fall)!");
    }

    if (cutDetected) {
      digitalWrite(ledPin, HIGH);

      // Beep rapidly
      if (millis() - lastBeepTime >= 100) {
        buzzerState = !buzzerState;
        digitalWrite(buzzerPin, buzzerState ? HIGH : LOW);
        lastBeepTime = millis();
      }

      if (millis() - cutTime > resetDelay) {
        cutDetected = false;
        digitalWrite(buzzerPin, LOW);
        digitalWrite(ledPin, LOW);
        Serial.println("✅ Auto-reset complete. System monitoring resumed.");
      }
    } else {
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      delay(200);
    }
  }

  delay(300);
}
