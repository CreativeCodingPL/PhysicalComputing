#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
Adafruit_SSD1306 display(0);

int pos = 31 / 2;
int ballX = random(127);
int ballY = random(31);
int ballDirX = 1;
int ballDirY = 1;
int points = 0;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  display.clearDisplay();
  //int x = analogRead(0);
  int y = analogRead(1);
  bool s = analogRead(2) < 10;
  int movement = map(y, 0, 1023, -5, 5);
  //int yL= map(y, 0, 1023, 0, 31);
  pos = constrain(pos + movement, 0, 31);
  display.drawFastVLine(0, pos - 3, 6, WHITE);
  display.drawFastVLine(1, pos - 3, 6, WHITE);

  display.fillCircle(ballX, ballY, 2, WHITE);
  if (ballX == 0) {
    //sprawdzic kolizje
    if ( abs(ballY - pos) > 6) {
      display.fillScreen(WHITE);
      points = 0;
      ballX = random(10, 127);
      ballY = random(31);
      ballDirX = 1;
      ballDirY = 1;
    }
    else {
      points++;
      ballDirX = -ballDirX;
    }
  }
  if (ballX == 127) {
    ballDirX = -ballDirX;
  }
  if (ballY == 0 || ballY == 31) {
    ballDirY = -ballDirY;
  }
  ballX += ballDirX;
  ballY += ballDirY;
  display.drawFastHLine(127 - points, 0, points, WHITE);
  display.display();
}
