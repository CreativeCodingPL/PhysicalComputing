#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

/*
 * UWAGA: kolejność pinów jest następująca: 1, 3, 2, 4
 * 
 * AccelStepper::FULL4WIRE - szybciej, ale mniej dokładnie
 * AccelStepper::HALF4WIRE - wolniej, ale dokładniej
 * 
 * @see Jak działa silnik - https://www.youtube.com/watch?v=B86nqDRskVU
 */
 
//AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);
AccelStepper stepper(AccelStepper::FULL4WIRE, in1, in3, in2, in4);

void setup() {
  stepper.setMaxSpeed(100);
  stepper.setSpeed(100);
}

void loop() {
  stepper.runSpeed();
}
