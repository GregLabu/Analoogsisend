int sensorPin = A0;
int sensorValue = 0;
float voltage = 0.0;
float temperatureC = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  voltage = sensorValue * (5.0 / 1023.0);
  temperatureC = (voltage - 0.5) * 100.0;

  if (temperatureC >= 15.0 && temperatureC <= 30.0) {
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" C");
  } else {
    Serial.println("Out of range");
  }
  delay(1000);
}
