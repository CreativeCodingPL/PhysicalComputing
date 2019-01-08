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
  stepper.moveTo(64*32*2); //pelen obrot bo 64 kroki i przekladnia 1:32 i 2* bo robi halfStep
}

void loop()
{
   
    if (stepper.distanceToGo() == 0)
      stepper.moveTo(-stepper.currentPosition());

    stepper.run();
}
