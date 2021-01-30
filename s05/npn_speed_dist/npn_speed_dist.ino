void setup() {
  pinMode(6, OUTPUT);
}

void loop() {
  int s = map(analogRead(A0), 0, 1023, 255, 0);
  analogWrite(6, s);  
  delay(1);                       
}
