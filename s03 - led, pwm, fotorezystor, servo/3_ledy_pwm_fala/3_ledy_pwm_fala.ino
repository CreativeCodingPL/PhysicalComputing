void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

float k1 = 1.0;
float k2 = 1.5;
float k3 = 2.0;

void loop() {
  
  int jasnosc1 = map( sin(k1) * 100, -100, 100, 0, 255 );
  int jasnosc2 = map( sin(k2) * 100, -100, 100, 0, 255 );
  int jasnosc3 = map( sin(k3) * 100, -100, 100, 0, 255 );
  
  analogWrite( 9, jasnosc1);
  analogWrite(10, jasnosc2);
  analogWrite(11, jasnosc3);

  k1 = k1 + 0.008;
  k2 = k2 + 0.008;
  k3 = k3 + 0.008;

  delay(1);
}