#include <NewPing.h>

NewPing sonar(12,11,20);

void setup() {
  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {

  int odleglosc = sonar.ping_cm();

  if( odleglosc <= 10 && odleglosc != 0 ){
    digitalWrite( LED_BUILTIN, HIGH );
  }else{
    digitalWrite( LED_BUILTIN, LOW );
  }
  
  Serial.println(odleglosc);
  delay(50);

}
