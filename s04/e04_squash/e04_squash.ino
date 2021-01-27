#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

enum states {GAME_OVER, GAME};
int state = GAME_OVER;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define POT A0

int x = 0;
int y = 16;
int dirY = 1;
int dirX = 1;
int R = 2;
int punkty = 0;
int pozycja = 0;
long time = 0;

int paletka = 10;

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
}

void loop() {
  switch (state) {
    case GAME_OVER:
      drawGameOver();
      checkTime();
      break;
    case GAME:
      drawGame();
      updateBall();
      break;
  }
}
void drawGameOver() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("      GAME OVER");
  display.println("        Wynik ");
  display.setTextSize(2);
  display.print("     ");
  display.println(punkty, DEC);
  display.display();
}
void checkTime() {
  if (millis() - time > 3000) {
    punkty = 0;
    state = GAME;
    time = millis();
  }
}
void drawGame() {
  display.clearDisplay();
  pozycja = map(analogRead(POT), 0, 1023, 0, 31);
  display.drawLine(127, pozycja - paletka / 2, 127, pozycja + paletka / 2, SSD1306_WHITE);
  display.drawLine(0, 0, 0, SCREEN_HEIGHT, SSD1306_WHITE);
  display.fillCircle(x, y, R, SSD1306_WHITE);
  display.display();
}
void updateBall() {
  if (millis() - time > 20) {
    x = x + dirX;
    y = y + dirY;
    time = millis();

    if (y >= SCREEN_HEIGHT - R) {
      dirY = -1;
    }
    if (y <= R) {
      dirY = 1;
    }
    if (x >= SCREEN_WIDTH - R) {
      if (abs(y - pozycja) < paletka / 2) {
        punkty += 1;
        dirX = -1;
      }
      else {
        x = 0;
        dirX = 1;
        state = GAME_OVER;
        time = millis();
      }
    }
    if (x <= R) {
      dirX = 1;
    }
  }
}
