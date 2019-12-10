
void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  analogWrite(3, 255);
  delay(400);
  analogWrite(3, 25);
  delay(600);
}
