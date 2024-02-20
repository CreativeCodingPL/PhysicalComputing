void setup() {
  pinMode(9, OUTPUT);
}

float k = 0;

void loop() {

  int jasnosc = map(sin(k) * 100, -100, 100, 0, 255);

  analogWrite(9, jasnosc);
  
  k = k + 0.005;
  
  delay(1);
}