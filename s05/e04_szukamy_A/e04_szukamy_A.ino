#include <AccelStepper.h>
#define HALFSTEP 8

AccelStepper stepper(HALFSTEP, 8, 10, 9, 11); //obejscie zeby dzialolo z silnikiem 28BYJ-48
//podlaczenie:
//8 - IN1
//9 - IN2
//10 - IN3
//11 - IN4

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
  if (abs(s1 - s2) < 5) {
    s1 = analogRead(A0);
    delay(2);
    stepper.run();
    s2 = analogRead(A0);
    delay(2);
    stepper.run();
  }
  //  Serial.println(abs(s1-s2));
}
