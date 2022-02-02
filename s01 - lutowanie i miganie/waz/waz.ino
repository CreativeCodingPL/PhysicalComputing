int i = 2;
void setup() {
  for(int i = 2; i<=12; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  digitalWrite(i, HIGH);
  digitalWrite(i+1, HIGH);
  digitalWrite(i+2, HIGH);
  delay(50);
  digitalWrite(i, LOW);
  digitalWrite(i+1, LOW);
  digitalWrite(i+2, LOW);
  i++;
  if(i>12) i = 2; 
}
