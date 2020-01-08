#include <Adafruit_NeoPixel.h>
#include <TM1637Display.h>

#define NUMPIXELS 4
#define NEOPIXEL_PIN 6

#define BTN_1_PIN 2
#define BTN_2_PIN 3
#define BTN_3_PIN 4

#define DISPLAY_CLK_PIN 8
#define DISPLAY_DIO_PIN 9

enum States { ANIMATING, WAITING };
enum Colors { RED, GREEN, BLUE };

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
TM1637Display display(8, 9);

int activePixel = 0;
int state = ANIMATING;
int pickedColor = RED;

long prevPixelsUpdate = 0;
int pixelUpdateInterval = 50;

long prevLotteryStopUpdate = 0;
int lotteryStopTime = 1000;

int waitPeriod = 1000;
long waitStartedTime = 0;


int colors[][3] = {
  {255,0,0}, // RED
  {0,255,0}, // GREEN
  {0,0,255} // BLUE
};

int buttonPins[] = {BTN_1_PIN,BTN_2_PIN,BTN_3_PIN};
int buttonStates[] = {0,0,0};


void setup() {

  pixels.begin();
  Serial.begin(9600);

  pinMode( BTN_1_PIN, INPUT_PULLUP );
  pinMode( BTN_2_PIN, INPUT_PULLUP );
  pinMode( BTN_3_PIN, INPUT_PULLUP );

}


void updatePixels(){

   pixels.clear(); 

   switch( state ){

    case WAITING:
      displayColor();
    break;
  
    case ANIMATING:
      lotteryAnim();
    break;
    
   }
   
   pixels.show();

}

void displayColor(){

   for (int i = 0; i < NUMPIXELS; i++) { 
    
      pixels.setPixelColor(i, colors[pickedColor][0], colors[pickedColor][1], colors[pickedColor][2]);
      
   }

}

void lotteryAnim(){

  for (int i = 0; i < NUMPIXELS; i++) { 

      if ( i == activePixel ) {
        pixels.setPixelColor(i, 255, 255, 255);
      } else {
        pixels.setPixelColor(i, 0, 0, 0);
      }
      
    }

    activePixel ++;
    if( activePixel > NUMPIXELS ){
      activePixel = 0;
    }
  
}

void checkButtons(){

  for( int i = 0; i < 3; i ++ ){
    buttonStates[i] = digitalRead( buttonPins[i] );
    //Serial.print( buttonStates[i] );
    //Serial.print(",");
  }
  //Serial.println();
  
}

void loop() {

  long currentTime = millis();

  //Serial.println( digitalRead( BTN_1_PIN ) );
  //Serial.println( digitalRead( BTN_2_PIN ) );
  //Serial.println( digitalRead( BTN_3_PIN ) );

  checkButtons();

  switch( state ){

    case ANIMATING:

      if( currentTime - prevLotteryStopUpdate >= lotteryStopTime  ){
        state = WAITING;
        waitStartedTime = currentTime;
        prevLotteryStopUpdate = currentTime;
      }
      
    break;

    case WAITING:

      if( currentTime - waitStartedTime >= 1000  ){

        state = ANIMATING;
        prevLotteryStopUpdate = currentTime;
 
      }

    break;
    
  }

  if( currentTime - prevPixelsUpdate >= pixelUpdateInterval  ){
    updatePixels();
    prevPixelsUpdate = currentTime;
  }
  
  
}
