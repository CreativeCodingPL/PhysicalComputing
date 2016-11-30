void setup() {

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);

}

void loop() {
  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  delay(150);
  digitalWrite(13, HIGH);
  delay(150);
  digitalWrite(13, LOW);
  delay(500);
}
