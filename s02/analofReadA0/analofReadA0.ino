void setup() {
  Serial.begin(9600);
}

void loop() {
  int napiecie = analogRead(A0);
  Serial.println(napiecie);
  delay(100);
}
