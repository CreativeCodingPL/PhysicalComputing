#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long previousMillis = 0; 
const long interval = 16;

int dotPos = 0;
int dir = 1;

void setup() {
  Serial.begin( 115200 );
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  Serial.println( SSD1306_WHITE );
}

void loop() {

  display.clearDisplay();
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if( dotPos == SCREEN_WIDTH - 1 ){
      dir = -1;
    }else if( dotPos == 0 ){
      dir = 1;
    }

    dotPos += dir;
    
  }
  display.drawPixel( dotPos, SCREEN_HEIGHT/2, 1 );
  display.display();
  
}
