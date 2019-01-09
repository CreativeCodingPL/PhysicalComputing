#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::HALF4WIRE, 8, 10, 9, 11); //obejscie zeby dzialolo z silnikiem 28BYJ-48
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
  stepper.moveTo(64*32*2); 
  /* pelen obrot wskazówki to 64*32*2 kroki, bo 32 kroki robi wewnętrzy rotor 
     i przekladnia jego ruchu za pomocą trybów to 1:64
     i jeszcze wszysko *2 bo na jeden krok przypadają dwa pół kroki 
     bo działamy w trybie Half Step dzięki ustawieniu AccelStepper::HALF4WIRE */
}

void loop()
{
   
    if (stepper.distanceToGo() == 0)
      stepper.moveTo(-stepper.currentPosition());

    stepper.run();
}
