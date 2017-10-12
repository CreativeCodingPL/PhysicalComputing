int firstSensor = 0;
int secondSensor = 0;
int inByte = 0;

void setup()
{
  Serial.begin(9600);
  establishContact();
}

void loop()
{
  if (Serial.available() > 0) {
    inByte = Serial.read();
    firstSensor = analogRead(0)/4;
    delay(10);
    secondSensor = analogRead(1)/4;
    Serial.write(firstSensor);
    Serial.write(secondSensor);              
  }
}

void establishContact() {
 while (Serial.available() <= 0) {
      Serial.write('A');
      delay(300);
  }
}
