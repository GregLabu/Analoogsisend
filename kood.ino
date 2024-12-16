int sensorPin = A0;
int sensorValue = 0;
float voltage = 0.0;
float temperatureC = 0.0;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);  // Kasutatakse 1.1 V sisemist referentspinget
}

void loop() {
  sensorValue = analogRead(sensorPin);
  voltage = sensorValue * (1.1 / 1023.0);  // Pinge arvutus
  temperatureC = (voltage - 0.5) * 100.0;  // Temperatuuri arvutus

  if (temperatureC >= 15.0 && temperatureC <= 30.0) {
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" C");
  } else {
    Serial.println("Out of range");
  }
  delay(1000);
}
