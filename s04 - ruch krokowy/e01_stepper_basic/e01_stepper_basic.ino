#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);

void setup() {
  stepper.setMaxSpeed(1000); //okolo 1/4 obrotu na sekunde bo pelen obrot to 64*64 steps
  stepper.setAcceleration(200);
  stepper.moveTo(64*64); //wykonaj pelem obrot, czyli zrob 64*64 kroki
}

void loop() {
  stepper.run(); //wprawia silnik w ruch i nie moze byc wywolywane wolniej niz jego max predkosc
}