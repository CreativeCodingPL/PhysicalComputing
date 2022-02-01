#include <Servo.h>

Servo serwo;

void setup() {
  serwo.attach(9);
  pinMode(A0, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  int odczyt = analogRead(A0);

  // zazwyczaj od 300 (ciemno) do 800 (jasno)
  int kat = map(odczyt, 300, 800, 0, 180);
  jasnosc = constrain(jasnosc, 0, 180);

  serwo.write(kat);
  delay(100);
  
  Serial.println(odczyt);
}
