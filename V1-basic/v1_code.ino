// v1.0 - Basic Hall Effect Sensor Reader
const int hallPin = A1;

void setup() {
  Serial.begin(9600);
  Serial.println("🔍 Magnetic Field Monitoring Started...");
}

void loop() {
  int sensorValue = analogRead(hallPin);
  Serial.print("Magnetic Field Value: ");
  Serial.println(sensorValue);
  delay(200); // To avoid flooding the serial monitor
}
