double t = 0;
void setup() {
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //           ( -1,1 ) -> (0, 2) -> (0, 1) -> (0,255)
  int wartosc = ( ( sin(t) + 1.0) / 2.0 ) * 255.0;
  analogWrite(11, wartosc);
  //Serial.println(odczyt);
  t = t + 0.5;
  delay(100);
}
