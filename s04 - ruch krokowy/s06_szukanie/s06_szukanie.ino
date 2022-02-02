#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);

void setup() {
  stepper.setMaxSpeed(1500); //okolo 1/4 obrotu na sekunde bo pelen obrot to 64*64 steps
  stepper.setAcceleration(1000);
}

boolean czyZnaleziona = false; //czy wskazowka znaleziona

void loop() {
  if(czyZnaleziona == false && analogRead(A0)>500) {
    //szukamy
    stepper.move(50);
  }
  if(analogRead(A0)<500) {
    czyZnaleziona = true;
  }

  
  stepper.run(); //wprawia silnik w ruch i nie moze byc wywolywane wolniej niz jego max predkosc
}
