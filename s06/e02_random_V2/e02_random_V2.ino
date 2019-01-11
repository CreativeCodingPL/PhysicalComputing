#include <LEDMatrixDriver.hpp>

LEDMatrixDriver lmd(1, 9);

void setup() {
  lmd.setEnabled(true);
  lmd.setIntensity(5);   // 0 = low, 10 = high
}


bool s = true;  // start with led on

void loop() {
  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++) {
      s = random(0, 100) > 90;
      lmd.setPixel(x, y, s);
    }

  lmd.display();

  delay(500);
}
