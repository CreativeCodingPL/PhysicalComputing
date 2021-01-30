#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);

/*
 * UWAGA: kolejność pinów jest następująca: 1, 3, 2, 4
 * 
 * AccelStepper::FULL4WIRE - szybciej, ale mniej dokładnie
 * AccelStepper::HALF4WIRE - wolniej, ale dokładniej
 * 
 * @see Jak działa silnik - https://www.youtube.com/watch?v=B86nqDRskVU
 */

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(200);
  stepper.moveTo(2000);
}

void loop() {
  if(stepper.distanceToGo() == 0) {
    stepper.moveTo(-stepper.currentPosition());
  }
  stepper.run();
}
