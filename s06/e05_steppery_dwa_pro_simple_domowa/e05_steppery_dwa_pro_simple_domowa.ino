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
  stepperA.setAcceleration(1600);
  stepperB.setMaxSpeed(1200);
  stepperB.setAcceleration(1700);
}

boolean znalezione = false; //czy znalazł poczatątki
int krokA = 1;
int krokB = 1;

void loop() {

  //szuka początku dla silkika A a potem B
  if(!znalezione) {
      stepperA.move(64*64); //pelen obrot
      //szuka poczatku dla A
      while (analogRead(A0) > 150) stepperA.run();
      stepperA.stop();
      delay(1000);
      //po znalezieniu dosuwa wskazówkę, żeby B miało miejsce
      stepperA.move(64*64*0.5);
      //czaka aż odsunie się wskazówka A
      while(stepperA.distanceToGo() != 0) stepperA.run();
      
      stepperB.move(64*64); //pelen obrot
      //szuka poczatku dla B
      while (analogRead(A0) > 150) stepperB.run();
      stepperB.stop();
      delay(1000);
      stepperB.move(64*64*0.5);
      //czaka aż odsunie się wskazówka B
      while(stepperB.distanceToGo() != 0) stepperB.run();

      znalezione = true; 
  }
  
  //potem wszyko inne, czyli zasadnicze ruchy
  if(znalezione) {
    if(stepperA.distanceToGo() == 0 && krokA < 6) {
      if(krokA == 1) stepperA.move(64*64*0.25);
      if(krokA == 2) stepperA.move(-64*64*0.5);
      if(krokA == 3) stepperA.move(64*64*0.5); 
      if(krokA == 4) stepperA.move(-64*64*0.1); 
      //wylacza zasilanie silnika, bo jak stoi to się grzeje
      if(krokA == 5) stepperA.disableOutputs(); 
      krokA++;
    }
    if(stepperB.distanceToGo() == 0 && krokB < 6) {
      if(krokB == 1) stepperB.move(-64*64*0.25);
      if(krokB == 2) stepperB.move(64*64*0.5);
      if(krokB == 3) stepperB.move(-64*64*0.5); 
      if(krokB == 4) stepperB.move(64*64*0.1); 
      //wylacza zasilanie silnika, bo jak stoi to się grzeje
      if(krokB == 5) stepperB.disableOutputs();
      krokB++;
    }
  }
  
  stepperA.run();
  stepperB.run();
}
