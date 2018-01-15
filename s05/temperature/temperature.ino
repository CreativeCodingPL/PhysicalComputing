//Sensor LM35
//https://playground.arduino.cc/Main/LM35HigherResolution

float tempC;
int reading;
int tempPin = 5;

void setup()
{
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop()
{
  reading = analogRead(tempPin);
  tempC = reading / 9.31;
  Serial.println(tempC);
  delay(1000);
}
