#include <AccelStepper.h>

//HALF4WIRE zeby dzialolo z silnikiem 28BYJ-48
//wazne 9 i 10 zamienione miejscami zeby dzialolo z silnikiem 28BYJ-48
AccelStepper stepper(AccelStepper::HALF4WIRE, 8, 10, 9, 11);
//podlaczenie do sterownika silnika:
//8 - IN1
//9 - IN2
//10 - IN3
//11 - IN4

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  stepper.setMaxSpeed(400);
  stepper.setAcceleration(200);
}

int pos = 100; //do jakiej pozycji aktualnie ide w celu poszukiwania A

void loop()
{
  int s1 = analogRead(A0); //sprawdza ile swiatla pada na fotorezystor
  stepper.runToNewPosition(pos); //zaczyna isc do pos czeka az do niej dojdzie
  int s2 = analogRead(A0); //sprawdza ile swiatla pada na fotorezystor
  pos = pos + 100; //kolejna pozycja wieksza o 100 od poprzedniej
  stepper.runToNewPosition(pos); //zaczyna isc do pos czeka az do niej dojdzie
  if (abs(s1 - s2) > 10) { //mamy A!!! jezeli zroznica w padajacym swietle wieksza niz 10.
    //znaczy ze wskazowka zaslonila fotorezystor. 10 dobrane arbitralnie
    delay(3000); //czekamy zeby kokazac gdzie jest i szukamy jeszcze raz :)
  }

  Serial.println(abs(s1 - s2)); //podgladamy co sie dzieje
}
