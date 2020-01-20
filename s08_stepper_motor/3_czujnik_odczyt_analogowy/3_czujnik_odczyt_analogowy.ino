void setup() {
  Serial.begin(9600);
}

void loop() {

  // Odczyt z pinu A0
  int sensorValue = analogRead(A0);

  /*
   * sensorValue - wartość z zakresu 0-1023 w zależności od gęstości materiału
   */
  if (sensorValue > 512) {
    Serial.println(sensorValue);
  }
  delay(1);
}
