#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);

void setup() {
  stepper.setMaxSpeed(1500); //okolo 1/4 obrotu na sekunde bo pelen obrot to 64*64 steps
  stepper.setAcceleration(1000);
  pinMode(2, INPUT_PULLUP); //PULLUP znaczy domysleni stan HIGH
}

void loop() {
  if(digitalRead(2) == LOW) {
    stepper.move(500); //wykonaj 100 krokow zaczynajac od miejsca gdzie aktualnie jestes
  }
  if(digitalRead(12) == LOW) {
    stepper.move(500); //wykonaj 100 krokow zaczynajac od miejsca gdzie aktualnie jestes
  }
  stepper.run(); //wprawia silnik w ruch i nie moze byc wywolywane wolniej niz jego max predkosc
}