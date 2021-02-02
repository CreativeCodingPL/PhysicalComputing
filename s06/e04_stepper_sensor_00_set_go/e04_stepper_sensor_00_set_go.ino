#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);

void setup() {
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(10000);
}

boolean nie_znaleziony = true; //czy znalazł poczatek
int krok = 1;

void loop() {
  //szukamy początku
  if (analogRead(A0) > 150 && nie_znaleziony) { 
    stepper.moveTo(stepper.currentPosition()+50);
  }
  //jak znajdzie
  if(analogRead(A0) < 150) {
      nie_znaleziony = false; 
  }
  //potem wszyko inne, czyli zasadnicze ruchy
  if(!nie_znaleziony) {
    if(stepper.distanceToGo() == 0 && krok < 5) {
      if(krok == 1) stepper.moveTo(stepper.currentPosition()+64*64); //pelen obort przeciwnie do zegara
      if(krok == 2) stepper.moveTo(stepper.currentPosition()-64*64*0.5); //pol obortou z kierumkiem zegara
      if(krok == 3) stepper.moveTo(stepper.currentPosition()+64*64*(3.0/4.0)); //3/4 obortu przeciwnie do zegara
      if(krok == 4) stepper.moveTo(stepper.currentPosition()+64*64*0.5); //pol obortou przeciwnie do zegara
      krok++;
      delay(1000); //na chwile staje na mejsu
    }
  }
  
  stepper.run();
}
