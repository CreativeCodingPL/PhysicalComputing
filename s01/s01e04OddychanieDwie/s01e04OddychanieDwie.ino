void setup() {
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
}

float k9 = 0;
float k6 = 0;

void loop() {
  int wartosc9 = 1000*sin(k9);
  int wartosc6 = 1000*sin(k6+PI);
  int jasnosc9 = map(wartosc9, -1000, 1000, 0, 255);
  int jasnosc6 = map(wartosc6, -1000, 1000, 0, 100);
  analogWrite(9, jasnosc9);
  analogWrite(6, jasnosc6);
  k9 = k9 + 0.003;
  k6 = k6 + 0.003;
  delay(1);
}
