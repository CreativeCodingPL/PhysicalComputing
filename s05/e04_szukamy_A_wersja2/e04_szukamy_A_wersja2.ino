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
  stepper.setMaxSpeed(600);
  stepper.setAcceleration(2000);
}

int pos = 0; //do jakiej pozycji aktualnie ide w celu poszukiwania A

void loop()
{
  stepper.runToNewPosition(pos); //zaczyna isc do pos czeka az do niej dojdzie
  int s = analogRead(A0); //sprawdza ile swiatla pada na fotorezystor
  pos = pos + 100; //kolejna pozycja wieksza o 100 od poprzedniej
  if (s > 500) { //mamy A!!! jezeli fotorezystor zasloniety to jest wiecej niz 500.
    //500 dobrane doswiadczalnie
    delay(3000); //czekamy zeby kokazac gdzie jest i szukamy jeszcze raz :)
  }

  Serial.println(s); //podgladamy co sie dzieje
}
