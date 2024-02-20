#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(9); // PWM
  
  pinMode(A1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  int jasnosc = map( analogRead(A1), 0, 1023, 300, -50);
  int c = constrain(jasnosc, 0, 180); 
  servo.write(c);

  Serial.print( analogRead(A1) );
  Serial.print( " -> ");
  Serial.print(jasnosc);
  Serial.print( " -> ");
  Serial.println(c);

  delay(100);
}
