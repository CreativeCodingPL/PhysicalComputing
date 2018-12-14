float t1 = 0; //popedza sinusa do działania do zmiany
float t2 = 0; //popedza sinusa do działania do zmiany

void setup() {
  
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  int jasnosc1 = map( sin(t1)*200, -200, 200, 0, 255 );
  analogWrite(6, jasnosc1);
  t1 = t1 + 0.003;

  int jasnosc2 = map( sin(t2)*200, -200, 200, 0, 255 );
  analogWrite(5, jasnosc2);
  t2 = t2 + 0.0031;

  delay(1); 
}
