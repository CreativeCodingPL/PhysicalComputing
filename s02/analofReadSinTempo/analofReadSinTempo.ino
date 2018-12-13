void setup() {
  pinMode(9, OUTPUT);
}

float k = 0;

void loop() {
  int napiecie = analogRead(A0);

  int jasnosc = map(sin(k)*150, -150, 150, 0, 255);  
  analogWrite(9, jasnosc); 
  k = k + 0.0001*napiecie; 
  
  delay(1);
}
