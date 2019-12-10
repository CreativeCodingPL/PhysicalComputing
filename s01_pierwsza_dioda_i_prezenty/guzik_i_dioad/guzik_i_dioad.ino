
void setup() {
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  int guzik = digitalRead(A0);
  if(guzik == HIGH) analogWrite(3, 255);
  if(guzik == LOW) analogWrite(3, 25);
}
