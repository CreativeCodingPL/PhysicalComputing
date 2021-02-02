#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(200);
}

void loop() {
  if (analogRead(A0) > 150) { 
    stepper.moveTo(stepper.currentPosition()+50);
  }
  stepper.run();
}
