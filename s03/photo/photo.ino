#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(9);
  pinMode(3, OUTPUT);
}

void loop() {
  int kat = map(analogRead(A2),0,1023,0,180);
  servo.write(kat);

  int jasnosc = analogRead(A0);
  if(jasnosc > 750){
    digitalWrite(3, LOW);
  } else {
    digitalWrite(3, HIGH);
  }
  delay(1);
}
