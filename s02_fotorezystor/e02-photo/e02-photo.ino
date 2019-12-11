void setup() {
  pinMode(A0, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int odczyt = analogRead(A0);
  analogWrite(11, 255 - odczyt / 4);
  Serial.println(odczyt);
}
