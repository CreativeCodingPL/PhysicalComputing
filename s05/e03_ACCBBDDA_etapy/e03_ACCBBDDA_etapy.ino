#include <AccelStepper.h>
#define HALFSTEP 8

AccelStepper stepper(HALFSTEP, 8, 10, 9, 11); //obejscie zeby dzialolo z silnikiem 28BYJ-48
//podlaczenie:
//8 - IN1
//9 - IN2
//10 - IN3
//11 - IN4


int etap = 1;
//zakladam ze na poczatku zegar jest w pozycji A
//etap 1) A->C
//etap 2) C->B
//etap 3) B->D
//etap 4) D->A
//jak etap 4 to wracam do etap 1

#define MiedzyLiterami -64*32*2 / 8 //definicja odleglosci miedzy literami w krokach

void setup()
{
  stepper.setMaxSpeed(400);
  stepper.setAcceleration(200);
  stepper.moveTo(0);
  //pelen obrot to 64*32*2 kroki
  //dlaczego:
  //bo 64 kroki rpbo wewnętrzny rotor na pełen obrót
  //i silnik ma przekladnie 1:32
  //i 2* bo robimy na każdy krok pół kroku dziŁając w trybie HALFSTEP
}

void loop()
{

  if (stepper.distanceToGo() == 0)
  {
    if (etap == 1) stepper.moveTo(MiedzyLiterami * 2); //A->C
    if (etap == 2) stepper.moveTo(MiedzyLiterami); //C->B
    if (etap == 3) stepper.moveTo(MiedzyLiterami * 3); //B->D
    if (etap == 4) stepper.moveTo(0); //D->A
    if (etap == 4)
      etap = 1;
    else
      etap++;
  }

  stepper.run();
}
