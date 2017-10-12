void setup() {
  pinMode(9, OUTPUT); 
}

float k = 0;

void loop() {
  int wartosc = 1000*sin(k);
  int jasnosc = map(wartosc, -1000, 1000, 20, 160);
  analogWrite(9, jasnosc);
  k = k + 0.003;
  delay(1);
}
