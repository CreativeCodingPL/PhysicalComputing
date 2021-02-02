void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT_PULLUP); //oznaczan domyslnie na pinie stan HIGH
}

void loop() {
  
  if( digitalRead(13) ) {
    Serial.println("button puszczony");
  } else {
    Serial.println("button wciśnięty");
  }
  
}
