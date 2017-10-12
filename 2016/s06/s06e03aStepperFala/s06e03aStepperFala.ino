#include <CheapStepper.h>

CheapStepper stepper; 

long lastFala = 0; //kiedy wystąpiło ostatnie odebranie fali, czyli prokroczenie ustalonego progu światła na fotorezystorze
long ledTimeStart = 0; //kiedy zapalono diodę przekzująca falę dalej
boolean fala = false; //czy fala została odebrana
boolean kierunek = false; //kierunek obrotu steppera
boolean ledOn = false; //czy dioda nadawcza może być zapalona

void setup() {
  pinMode(13, OUTPUT); //sterowanie diodą nadawczą
}

void loop() {
    //Warunek ustalający próg wyzwolenia oznaczający odbiór fali i zabezpieczenie przed ponownym przypadkowym odbiorem, czyli kolejne możliwe odebranie fali dopiero po 500 ms
    if( analogRead(A0) > 800 && millis()-lastFala>500) {
      fala = true; //zaznaczamy ze fala została odebrana
      lastFala = millis(); //aktualizujemy czasu odebrania fali  
    }

    if(fala) { //jeżeli fala została odebrana
      fala = false; //kasujemy zaznaczenie odebrania fali
      stepper.newMoveDegrees(kierunek, 90); //inicjujemy obracamy o 90 stopni w kierunku true zgodym z kierunkiem zegara lub false przeciwnie do kierunku zegara 
      kierunek = !kierunek; //zmieniamy przyszły kierunek na przeciwny
      ledOn = true; //ustalamy że dioda nadawcza może się zapalić
      ledTimeStart = millis(); //zaczynamy mierzyć czas względem którego wyznaczymy opóźnienie w zapaleniu diody nadawczej
    }
    //jeżeli możemy zapalić diodę i nadszedł czas jej zapalenia, czyli nadszedł czas przekazania fali dalej tu ustalony na 1500ms
    if(ledOn && millis() - ledTimeStart > 1500) {
      ledOn = false; //zabezpieczenie przed ponownym zapaleniem diody przed czasem
      digitalWrite(13, HIGH);
    }
    //jeżeli nadszedł czas zgaszenia diody nadawczej to ją gasimy, czyli dioda pali się przez 300ms bo gasimy jak jest 1500+300 od ledTimeStart a zapalaliśmy 1500 od ledTimeStart
    if(millis() - ledTimeStart > 1500+300) {
      digitalWrite(13, LOW);
    }
    
    stepper.run(); //aktualizuje pozycję stepera żeby doszedł w końcu do zainicjowanej pozycji
}

