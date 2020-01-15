#include <Servo.h>

Servo lasery;

void setup() {
  lasery.attach(6);
  pinMode(11, OUTPUT);
}

void laserMruga() {
  digitalWrite(11, HIGH);
  delay(20);
  digitalWrite(11, LOW);  
}

//w tej wersji powstają linię łączące punkty
//bo serwo zaczyna się poruszać do wskazanej pozycji
//i zanim tam dotrze włącza się laser

void loop() {
  lasery.write(90);
  laserMruga();
  delay(70);
  lasery.write(90 - 3);
  laserMruga();
  delay(70);
  lasery.write(90);
  laserMruga();
  delay(70);
  lasery.write(90 + 3);
  laserMruga();
  delay(100);
}
