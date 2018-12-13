#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800);

float tempC;
int reading;
int tempPin = 5;

void setup()
{
  analogReference(INTERNAL);
  Serial.begin(9600);

  strip.begin();
  strip.show();
}

void loop()
{
  reading = analogRead(tempPin);
  tempC = reading / 9.31;
  Serial.println(tempC);

  for (int i = 0; i < strip.numPixels(); i++) {
    int red = map(tempC, 20, 50, 0, 255);
    int green = map(tempC, 50, 20, 0, 255);
    strip.setPixelColor(i, red, green, 0);
  }
  strip.show();
  delay(1000);
}
