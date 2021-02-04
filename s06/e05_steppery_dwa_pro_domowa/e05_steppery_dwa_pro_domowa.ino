#include <AccelStepper.h>

//zmineiłem kolejność kabli, żeby ładniej wyglądało 
//na rysunku z połączeniami :)

//motor a
#define in1a 11
#define in2a 10
#define in3a 9
#define in4a 8

//motor b
#define in1b 5
#define in2b 4
#define in3b 3
#define in4b 2

//zmieniłem kolejność z 1,3,2,4 na 4,2,3,1 żeby dodatnie kroki
//poruszały zgodnie z ruchem wskazówek zegara
AccelStepper stepperA(AccelStepper::HALF4WIRE, in4a, in2a, in3a, in1a);
AccelStepper stepperB(AccelStepper::HALF4WIRE, in4b, in2b, in3b, in1b);

void setup() {
  stepperA.setMaxSpeed(1200);
  stepperA.setAcceleration(3000);
  stepperB.setMaxSpeed(1200);
  stepperB.setAcceleration(3000);
}

boolean znalezionyA = false; //czy znalazł poczatek
int krokA = 1;
boolean znalezionyB = false; //czy znalazł poczatek
int krokB = 1;

void loop() {
  
  //jak znajdzie początek to zakrywa sensor więć miej niż 150
  //zaczynamy od tego bo może się zdarzyć, że przypadkiem na starcie
  //jest już na początku
  if(analogRead(A0) < 150 && !znalezionyA) {
      znalezionyA = true; 
      delay(1000);
      //po znalezieniu dosuwa wskazówkę, żeby B miało miejsce
      stepperA.move(64*64*0.5);
      //czaka aż odsunie się wskazówka A
      while(stepperA.distanceToGo() != 0) stepperA.run();
  }
  //szuka B jak zajdzie A
  if(analogRead(A0) < 150 && znalezionyA && !znalezionyB) {
      znalezionyB = true; 
      delay(1000);
      //to podowuje ze na starcie wskazowki będą na zewnątrz
      stepperB.move(64*64*0.5);
      //czaka aż odsunie się wskazówka B
      while(stepperB.distanceToGo() != 0) stepperB.run();
  }
  
  //jak nie znalazl początku to przesuwa o 250 kroków
  if (!znalezionyA) { 
    stepperA.move(250); 
  }
  //znalal A to teraz przesuwa B
  if (znalezionyA && !znalezionyB) { 
    stepperB.move(250); 
  }

  //potem wszyko inne, czyli zasadnicze ruchy
  if(znalezionyA && znalezionyB) {
    if(stepperA.distanceToGo() == 0 && krokA < 5) {
      if(krokA == 1) stepperA.move(64*64*0.25);
      if(krokA == 2) stepperA.move(-64*64*0.5);
      if(krokA == 3) stepperA.move(64*64*0.5); 
      if(krokA == 4) stepperA.move(-64*64*0.1); 
      if(krokA == 5) stepperA.disableOutputs();
      krokA++;
    }
    if(stepperB.distanceToGo() == 0 && krokB < 5) {
      if(krokB == 1) stepperB.move(-64*64*0.25);
      if(krokB == 2) stepperB.move(64*64*0.5);
      if(krokB == 3) stepperB.move(-64*64*0.5); 
      if(krokB == 4) stepperB.move(64*64*0.1); 
      krokB++;
    }
  }
  
  stepperA.run();
  stepperB.run();
}
