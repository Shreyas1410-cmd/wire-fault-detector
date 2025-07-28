// v3.0 - Smoothing logic + buzzer alert + auto reset

const int hallPin = A1;
const int ledPin = 13;
const int buzzerPin = 8;
const int threshold = 650;
const int smoothCount = 3;

int readings[smoothCount];
int index = 0;

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
  Serial.println("🔁 v3.0 - Monitoring system with buzzer & smoothing...");
}

void loop() {
  int sensorValue = analogRead(hallPin);

  readings[index] = sensorValue;
  index = (index + 1) % smoothCount;

  Serial.print("Magnetic Field: ");
  Serial.println(sensorValue);

  bool isCutLikely = true;
  for (int i = 1; i < smoothCount; i++) {
    if (readings[i] >= threshold || readings[i] > readings[i - 1]) {
      isCutLikely = false;
      break;
    }
  }

  if (isCutLikely && !cutDetected) {
    cutDetected = true;
    cutTime = millis();
    Serial.println("⚠️ ALERT: WIRE CUT CONFIRMED (3 decreasing readings)!");
  }

  if (cutDetected) {
    digitalWrite(ledPin, HIGH);
    if (millis() - lastBeepTime >= 100) {
      buzzerState = !buzzerState;
      digitalWrite(buzzerPin, buzzerState ? HIGH : LOW);
      lastBeepTime = millis();
    }

    if (millis() - cutTime > resetDelay) {
      cutDetected = false;
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      Serial.println("✅ Auto-reset done. System monitoring resumed.");
    }
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  delay(300);
}
