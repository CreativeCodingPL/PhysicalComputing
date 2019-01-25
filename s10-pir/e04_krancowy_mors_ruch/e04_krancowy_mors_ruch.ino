#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 11

#define BRIGHTNESS 50

Adafruit_NeoPixel pasek = Adafruit_NeoPixel(NUM_LEDS, 9, NEO_GRBW + NEO_KHZ800);

void setup() {

  pinMode(6, INPUT_PULLUP);

  pasek.setBrightness(BRIGHTNESS);
  pasek.begin();
  pasek.show(); // Initialize all pixels to 'off'

}

int poz = 0;

void loop() {
  bool wcisniety = digitalRead(6); //pir OUT podlaczony do pinu 6

  if (wcisniety) {
    pasek.setPixelColor(poz, pasek.Color(0, 0, 0, 255));
    tone(3, 1500, 50);  //ruch jest zmienna logiczna wiec sama w sobie tworzy warunek
  } 
  else {
    pasek.setPixelColor(poz, pasek.Color(0, 0, 0, 0));
  }

  pasek.show();
  poz++;
  if (poz >= NUM_LEDS) poz = 0;
  delay(50);
}
