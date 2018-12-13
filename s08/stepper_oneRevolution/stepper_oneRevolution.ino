#include <Stepper.h>

const int stepsPerRevolution = 32;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);  //IN1, IN2, IN3, IN4

void setup() {
  myStepper.setSpeed(60); //60 rpm
}

void loop() {
  myStepper.step(stepsPerRevolution*64);
  delay(1000);
  //jeden obrot w druga strone
  myStepper.step(-stepsPerRevolution*64);
  delay(1000);
}

