#include <NewPing.h>

NewPing sonar(12,11,20);

void setup() {
  
  Serial.begin(9600);
  
}

void loop() {

  int odleglosc = sonar.ping_cm();

  // wypisujemy odleglosc na port szeregowy (serial)
  Serial.println(odleglosc); // uwaga - println do wartosci dokleja znak nowej linii - korzystamy z tego potem przy odczytywaniu w prcessing 
  delay(100);

}
