// v2.0 - Added LED visual feedback for cut detection
const int hallPin = A1;
const int ledPin = 13;
const int threshold = 650;

void setup() {
  pinMode(hallPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("🟢 v2.0 - System Initialized. Monitoring...");
}

void loop() {
  int sensorValue = analogRead(hallPin);
  Serial.print("Magnetic Field Value: ");
  Serial.println(sensorValue);

  if (sensorValue < threshold) {
    Serial.println("❌ WIRE CUT DETECTED!");
    digitalWrite(ledPin, HIGH); // LED stays ON when cut detected
  } else {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
  }
}
