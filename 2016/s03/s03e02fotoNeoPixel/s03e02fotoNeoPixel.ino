#include <Adafruit_NeoPixel.h>

int NUMPIXELS = 5;
int PIN = 6;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(A0, INPUT);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  int odczyt = analogRead(A0);
  int ile = map(odczyt, 0, 1023, 0, NUMPIXELS);
  pixels.clear();
  for (int i = 0; i < ile; i++) {
    pixels.setPixelColor(i, pixels.Color(100, 100, 100)); // Moderately bright green color.
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(50);
}
