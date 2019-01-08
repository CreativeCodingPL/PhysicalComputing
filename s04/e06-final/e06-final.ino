#include <Keyboard.h>

int Trig = 2;
int Echo = 3;
int CM;
long CZAS;

int micPin = 4;
int previousMicState = LOW;
long lastChange = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  pinMode(micPin, INPUT);
  Keyboard.begin();
}

void loop()
{
  pomiar_odleglosci();
  int micState = digitalRead(micPin);
  if (
    micState == HIGH &&
    previousMicState == LOW &&
    millis() - lastChange > 100 &&
    CM > 1 &&
    CM < 101
  )
  {
    int znak = map(CM, 2, 100, 97, 122);
    Keyboard.write((char)znak);
    lastChange = millis();
  }
  previousMicState = micState;
}

void pomiar_odleglosci ()
{
  digitalWrite(Trig, LOW);        //ustawienie stanu wysokiego na 2 uS - impuls inicjalizujacy - patrz dokumentacja
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);       //ustawienie stanu wysokiego na 10 uS - impuls inicjalizujacy - patrz dokumentacja
  delayMicroseconds(15);
  digitalWrite(Trig, LOW);
  digitalWrite(Echo, HIGH);
  CZAS = pulseIn(Echo, HIGH);
  CM = CZAS / 58;                //szerokość odbitego impulsu w uS podzielone przez 58 to odleglosc w cm - patrz dokumentacja
}
