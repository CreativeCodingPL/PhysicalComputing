#include <AccelStepper.h>
#define HALFSTEP 8

AccelStepper stepper(HALFSTEP, 8, 10, 9, 11); //obejscie zeby dzialolo z silnikiem 28BYJ-48
//podlaczenie:
//8 - IN1
//9 - IN2
//10 - IN3
//11 - IN4

void setup()
{  
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(400);
  stepper.setAcceleration(200);
  stepper.moveTo(-64*32*2 / 8); //tyle ktokow miedzy A i B, ale też C i D itd.
  //pelen obrot to 64*32*2 kroki
  //dlaczego: 
  //bo 64 kroki rpbo wewnętrzny rotor na pełen obrót
  //i silnik ma przekladnie 1:32 
  //i 2* bo robimy na każdy krok pół kroku dziŁając w trybie HALFSTEP
}

void loop()
{
   
    if (stepper.distanceToGo() != 0)
      stepper.run();
}
