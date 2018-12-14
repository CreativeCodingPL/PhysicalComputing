float t = 0; //popedza sinusa do działania do zmiany

void setup() {
  
  pinMode(6, OUTPUT);

}

void loop() {
  int jasnosc = map( sin(t)*200, -200, 200, 0, 255 );
  analogWrite(6, jasnosc);
  t = t + 0.003;
  delay(1); 
}
