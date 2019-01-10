#include <AccelStepper.h>

//HALF4WIRE zeby dzialolo z silnikiem 28BYJ-48
//wazne 9 i 10 zamienione miejscami zeby dzialolo z silnikiem 28BYJ-48
AccelStepper stepper(AccelStepper::HALF4WIRE, 8, 10, 9, 11);
//podlaczenie:
//8 - IN1
//9 - IN2
//10 - IN3
//11 - IN4
//5V - +
//GND - -

int etap = 0;
//etap 0) szukamy pozycji litery A
//etap 1) A->C
//etap 2) C->B
//etap 3) B->D
//etap 4) D->A
//jak etap 4 to wracam do etap 1

#define MiedzyLiterami -64*32*2 / 8 //definicja odleglosci miedzy literami w krokach
/*
   pelen obrot wskazówki to 64*32*2 kroki, bo 32 kroki robi wewnętrzy rotor
   i przekladnia jego ruchu za pomocą trybów to 1:64
   i jeszcze wszysko *2 bo na jeden krok przypadają dwa pół kroki
   bo działamy w trybie Half Step dzięki ustawieniu AccelStepper::HALF4WIRE
   +/- ustala kierunek obrotu.
   /8 bo litery są rozłożone na tarczy co 1/8 obrotu.
*/

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  stepper.setMaxSpeed(500);
  stepper.setAcceleration(4000);
}

int pos = 0; //do jakiej pozycji aktualnie ide w celu poszukiwania A

void loop()
{
  if (etap == 0) { //szuakmy A
    stepper.runToNewPosition(pos); //zaczyna isc do pos czeka az do niej dojdzie
    int s = analogRead(A0); //sprawdza ile swiatla pada na fotorezystor
    pos = pos + 50; //kolejna pozycja wieksza o 50 od poprzedniej
    stepper.runToNewPosition(pos); //zaczyna isc do pos czeka az do niej dojdzie
  if (s > 500) { //mamy A!!! jezeli fotorezystor zasloniety to jest wiecej niz 500.
    //500 dobrane doswiadczalnie
      etap = 1; //bo znaleslismy A
      stepper.setCurrentPosition(0); //zerujemy pozycje, bo zakladamy, że A jest na pozycji 0. Od niego zaczynamy etapy ruchu
      delay(200);
//      stepper.runToNewPosition(90); //mala korekta pozycji zeby doklannie na A
//      stepper.setCurrentPosition(0);
    }
    Serial.println(s);
  }
  else if (stepper.distanceToGo() == 0)
  {
    if (etap == 1) stepper.moveTo(MiedzyLiterami * 2); //A->C
    if (etap == 2) stepper.moveTo(MiedzyLiterami); //C->B
    if (etap == 3) stepper.moveTo(MiedzyLiterami * 3); //B->D
    if (etap == 4) stepper.moveTo(0); //D->A wrazamy do A czyli na pozycje 0
    if (etap == 4) etap = 1; else etap++;
  }

  stepper.run();  //wszysko obliczna i wykoneju kroki silnika, wywolywac jak najczesciej
}
