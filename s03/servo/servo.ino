#include <Servo.h>
Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int kat = map(analogRead(A2),0,1023,0,180);
  //Serial.println(kat);
  servo.write(kat);
  delay(1);
}
