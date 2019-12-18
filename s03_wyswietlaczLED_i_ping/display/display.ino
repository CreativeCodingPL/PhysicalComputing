#include <TM1637Display.h>
///                   clk, dio
TM1637Display display(2, 3);
int i = 0;

uint8_t segments[][4] = {
  { 48, 0, 0,  0 }, // 48 = SEG_E + SEG_F
  {  9, 0, 0,  0 },
  {  6, 0, 0,  0 },
  { 0, 48, 0, 0 },
  { 0, 9, 0, 0},
  { 0, 6, 0, 0 },
  { 0, 128, 0, 0 },
  { 0, 0, 48, 0 },
  { 0, 0, 9, 0 },
  { 0, 0, 6, 0 },
  { 0, 0, 0, 48},
  { 0, 0, 0, 9},
  { 0, 0, 0, 6 }
};
void setup() {
  display.setBrightness(255);
}

void loop() {
  i++; // i = i + 1;
  if (i > 12) {
    i = 0;
  }
  //display.showNumberDec(i, true);
  display.setSegments(segments[i]);
  delay(10);

}
