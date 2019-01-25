#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
Adafruit_SSD1306 display(0);

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  int x = analogRead(0);
  int y = analogRead(1);
  bool s = analogRead(2) < 10;
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.println(s);
  display.drawPixel(map(x, 0, 1023, 0, 127), map(y, 0, 1023, 0, 31), WHITE);
  display.display();
}
