#include <AccelStepper.h>

//zmineiłem kolejność kabli, żeby ładniej wyglądało 
//na rysunku z połączeniami :)
#define in1 11
#define in2 10
#define in3 9
#define in4 8

//zmieniłem kolejność z 1,3,2,4 na 4,2,3,1 żeby dodatnie kroki
//poruszały zgodnie z ruchem wskazówek zegara
AccelStepper stepper(AccelStepper::HALF4WIRE, in4, in2, in3, in1);

void setup() {
  stepper.setMaxSpeed(1500);
  stepper.setAcceleration(3000);
}

boolean nie_znaleziony = true; //czy znalazł poczatek
int krok = 1;

void loop() {
  
  //jak znajdzie początek to zakrywa sensor więć miej niż 150
  //zaczynamy od tego bo może się zdarzyć, że przypadkiem na starcie
  //jest już na początku
  if(analogRead(A0) < 150) {
      nie_znaleziony = false; 
  }
  
  //jak nie znalazl początku to przesuwa o 250 kroków
  if (nie_znaleziony) { 
    stepper.move(250); 
    //move(250) - to samo co - moveTo(stepper.currentPosition()+250);
  }

  //potem wszyko inne, czyli zasadnicze ruchy
  if(!nie_znaleziony) {
    if(stepper.distanceToGo() == 0 && krok < 5) {
      if(krok == 1) stepper.move(64*64); //pelen obort zgodnie z ruchem zegara
      if(krok == 2) stepper.move(-64*64*0.5); //pol obortou przeciwnie do ruchemu zegara
      if(krok == 3) stepper.move(64*64*3.0/4.0); // 3/4 obortu zgodnie z ruchem zegara
      if(krok == 4) stepper.move(64*64*0.5); //pol obortou zgodnie z ruchem zegara
      delay(1000); //na chwile staje na mejsu
    }
  }
  
  stepper.run();
}
