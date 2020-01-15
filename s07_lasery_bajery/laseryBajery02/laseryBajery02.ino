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

//w tej wersji pojawiają się tylko punkty
//bo czekamy aż serwo dotrze do wskazanej pozycji
//i dopiero po tym czasie włączamy laser
//eksoerymentalnie ustalilśmy, że delay(70) wystarczy 
//by serwo dotarło zanim zapoali się laser 

void loop() {
  lasery.write(90);
  delay(70);
  laserMruga();
  lasery.write(90 - 3);
  delay(70);
  laserMruga();
  lasery.write(90);
  delay(70);
  laserMruga();
  lasery.write(90 + 3);
  delay(100);
  laserMruga();
}
