void setup() {
  Serial.begin(9600);
}
void loop() {
  int val = analogRead(A0) / 4;
  Serial.write(val);
  delay(10);
}
