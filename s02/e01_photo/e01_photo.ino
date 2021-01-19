void setup() {
  pinMode(A0, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int odczyt = analogRead(A0);
  int jasnosc = map(odczyt, 20, 600, 255, 0);
  analogWrite(11, jasnosc);
  Serial.println(odczyt);
}
