#include <AccelStepper.h>
#define HALFSTEP 8

AccelStepper stepper(HALFSTEP, 8, 10, 9, 11); //obejscie zeby dzialolo z silnikiem 28BYJ-48
//podlaczenie:
//8 - IN1
//9 - IN2
//10 - IN3
//11 - IN4


int etap = 0;
//etap 0) szukamy pozycji litery A
//etap 1) A->C
//etap 2) C->B
//etap 3) B->D
//etap 4) D->A
//jak etap 4 to wracam do etap 1

#define MiedzyLiterami -64*32*2 / 8 //definicja odleglosci miedzy literami w krokach

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  stepper.setMaxSpeed(400);
  stepper.setAcceleration(200);
  stepper.moveTo(64 * 32 * 2 * 2); // dwa pelne obroty
  
}
int s1 = 0;
int s2 = 0;
void loop()
{
  if(etap == 0) { //szuakmy A
    s1 = analogRead(A0);
    delay(2);
    stepper.run();
    s2 = analogRead(A0);
    delay(2);
    stepper.run();
    if (abs(s1 - s2) > 6) {
      etap = 1; //znaleslismy A
      stepper.setCurrentPosition(0);
      delay(200);
      stepper.runToNewPosition(90); //mala korekta pozycji zeby doklannie na A
      stepper.setCurrentPosition(0);
    }
    Serial.println(abs(s1-s2));
  }
  else if (stepper.distanceToGo() == 0)
  {
    if (etap == 1) stepper.moveTo(MiedzyLiterami * 2); //A->C
    if (etap == 2) stepper.moveTo(MiedzyLiterami); //C->B
    if (etap == 3) stepper.moveTo(MiedzyLiterami * 3); //B->D
    if (etap == 4) stepper.moveTo(0); //D->A
    if (etap == 4)
      etap = 1;
    else
      etap++;
  }

  stepper.run();
}
