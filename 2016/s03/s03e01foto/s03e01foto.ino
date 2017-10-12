#include <Servo.h>

Servo machacz;

void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  machacz.attach(9);
}

int kat = 90; 
void loop() {
   int odczyt1 = digitalRead(7);
   int odczyt2 = digitalRead(8);
   if(0 == odczyt1) kat--;
   if(0 == odczyt2) kat++;
   //if(kat < 10) kat = 10;
   //if(kat > 170) kat = 170;
   kat = constrain(kat, 10, 170);
   machacz.write(kat);
   delay(20);
}
