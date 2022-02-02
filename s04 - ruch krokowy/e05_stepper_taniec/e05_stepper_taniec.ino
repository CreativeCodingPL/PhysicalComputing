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

int czasStart = millis()+random(500, 2000);

void loop() {
  if(millis()-czasStart > 0) { //wywoluj move co 0.5s do 2s
    czasStart = millis()+random(5000, 15000);
    stepper.move(random(-200, 200));//random w arduino daje tylko liczby calkowite
    //stepper.move(random(-1, 2)*200);//random w arduino daje tylko liczby calkowite
  }
  stepper.run(); //wprawia silnik w ruch i nie moze byc wywolywane wolniej niz jego max predkosc
}