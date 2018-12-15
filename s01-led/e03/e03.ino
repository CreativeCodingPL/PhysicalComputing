
int pinNum = 11;

void setup() {
  pinMode(pinNum, OUTPUT);

}
void loop() {

  int t = random( 2, 50 );
  
  for (int i = 0; i < 255; i++) {
    analogWrite(pinNum, i);
    delay( t );
  }
  delay(100);

  t = random( 2, 50 );
  
  for (int i = 255; i >0; i--) {
    analogWrite(pinNum, i);
    delay( t );
  }
  delay(100);
}

