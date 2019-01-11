#include <LEDMatrixDriver.hpp>


// The LEDMatrixDriver class instance
LEDMatrixDriver lmd(1, 9);

void setup() {
  // init the display
  lmd.setEnabled(true);
  lmd.setIntensity(2);   // 0 = low, 10 = high
}

bool s = true;  // start with led on

void loop() {
  int x = random(8);
  int y = random(8);
  s = !s;
  lmd.setPixel(x, y, s);

  lmd.display();

  delayMicroseconds(100);
}
