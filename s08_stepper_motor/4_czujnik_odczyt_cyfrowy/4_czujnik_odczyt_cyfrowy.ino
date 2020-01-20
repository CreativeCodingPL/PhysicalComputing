void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // Odczyt z pinu 12 (D12)
  int sensorValue = digitalRead(12);

  /*
   * sensorValue - wartość 0 lub 1 (jest lub nie ma)
   */
  if (sensorValue == 1) {
    Serial.println(sensorValue);
  }
  
  delay(1);
}
