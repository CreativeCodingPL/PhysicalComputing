#include <Servo.h>

Servo serwus;

void setup() {
  serwus.attach(9);
  Serial.begin(9600);
}

void loop() {
   int ile = analogRead(A0);
   int kat = map(ile, 0, 1023, 0, 180);
   Serial.println(ile);
   serwus.write(kat);
   delay(50);
}
