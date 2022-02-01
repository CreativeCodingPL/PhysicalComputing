void setup() {
  Serial.begin(9600);
}

void loop() {
  int odczyt = analogRead(A0);
  Serial.println(odczyt);
}
