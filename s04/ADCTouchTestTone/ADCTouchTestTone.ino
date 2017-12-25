#include <ADCTouch.h>

int baza = 0;

void setup() 
{
  Serial.begin(9600);
  baza = ADCTouch.read(A0, 500);
}

void loop() {
  int wartosc = ADCTouch.read(A0);
  Serial.println(wartosc-baza);
  tone(4, (wartosc-baza)*10);
  delay(10);
}
