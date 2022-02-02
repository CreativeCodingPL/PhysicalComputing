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
 */

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(200);
  pinMode(13, INPUT_PULLUP); //oznaczan domyslnie na pinie stan HIGH
}

void loop() {
  if (digitalRead(13) == LOW) { 
    stepper.moveTo(stepper.currentPosition()+50);
  }
  stepper.run();
}
