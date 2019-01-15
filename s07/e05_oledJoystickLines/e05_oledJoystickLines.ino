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
  display.clearDisplay();
  int x = analogRead(0);
  int y = analogRead(1);
  bool s = analogRead(2) < 10;
  int xL = map(x, 0, 1023, 0, 127);
  int yL= map(y, 0, 1023, 0, 31);
  
  for(int i=0;i<31;i+=127/xL){
    display.drawFastHLine(0, i, 127, WHITE);
  }
  
  for(int i=0;i<127;i+=31/yL){
    display.drawFastVLine(i, 0, 31, WHITE);
    
  }

  display.display();
}
