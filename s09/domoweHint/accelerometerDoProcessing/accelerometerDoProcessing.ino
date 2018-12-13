#include <Wire.h>
#include <FaBo3Axis_ADXL345.h>

FaBo3Axis przyspieszeniomierz;

void setup()
{
  Serial.begin(9600); 

  przyspieszeniomierz.configuration();
  przyspieszeniomierz.powerOn();
}

void loop() {
  int x;
  int y;
  int z;
  
  przyspieszeniomierz.readXYZ(&x,&y,&z);

  Serial.write(255); //jak 255 to info ze mamy poczatek transmisji paczki trzech liczb 
  Serial.write(x+127);
  Serial.write(y+127);
  Serial.write(z+127);
  delay(100);
}
