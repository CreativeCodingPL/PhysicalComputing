void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT_PULLUP); //oznaczan domyslnie na pinie stan HIGH
}

void loop() {
//  Serial.println(digitalRead(13));
  int p1 = digitalRead(13);
  if( p1 == 1 ) {
    Serial.println("button puszczony");
  }
  if( p1 == 0 ) {
    Serial.println("button wciśnięty");
  }

}
