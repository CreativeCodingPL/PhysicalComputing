void setup() {
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int i = random(2, 14);
  digitalWrite(i, HIGH);
  delay(random(500));
  digitalWrite(i, LOW);
  delay(random(700));

}
