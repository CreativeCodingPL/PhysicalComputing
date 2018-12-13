// Program odczytuje temperaturę z czujnika
#include <Adafruit_NeoPixel.h>
#include <OneWire.h>
#include <DS18B20.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800);

// Numer pinu do którego podłaczasz czujnik
#define ONEWIRE_PIN 2

// Adres czujnika
byte address[8] = {0x28, 0x97, 0xB9, 0xC4, 0x9, 0x0, 0x0, 0x2F};

OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);

void setup() {
  while (!Serial);
  Serial.begin(9600);

  sensors.begin();
  sensors.request(address);
  strip.begin();
  strip.show();
}

void loop() {
  if (sensors.available())
  {
    float temperature = sensors.readTemperature(address);

    Serial.print(temperature);
    Serial.println(F(" 'C"));

    sensors.request(address);
    for (int i = 0; i < strip.numPixels(); i++) {
      int red = map(temperature, 20, 40, 0, 255);
      int green = map(temperature, 40, 20, 0, 255);
      strip.setPixelColor(i, red, green, 0);
    }
    strip.show();
  }

  // tu umieść resztę twojego programu
  // Będzie działał bez blokowania
}
