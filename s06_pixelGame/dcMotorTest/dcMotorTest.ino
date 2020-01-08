#include <TM1637Display.h>
///                   clk, dio
TM1637Display display(8, 9);

#define MOTOR_PIN_A 10
#define MOTOR_PIN_B 11

#define BTN_1_PIN 2
#define BTN_2_PIN 3
#define BTN_3_PIN 4

#define MAX_SPEED 255
#define MIN_SPEED 50

enum Direction { FORWARD, BACKWARD };
int currentDir = FORWARD;
int speed = 0;


void checkButtons(){
  if( digitalRead( BTN_1_PIN ) == LOW ){
    currentDir = FORWARD;
  }

  if( digitalRead( BTN_2_PIN ) == LOW ){
    currentDir = BACKWARD;
  }

  if( digitalRead( BTN_3_PIN ) == LOW ){

    speed ++;
    if( speed >= 100 ){
      speed = 0;
    }
    
  }
}


void setup() {
  
  // put your setup code here, to run once:
  pinMode( MOTOR_PIN_A, OUTPUT);
  pinMode( MOTOR_PIN_B, OUTPUT);

  pinMode( BTN_1_PIN, INPUT_PULLUP );
  pinMode( BTN_2_PIN, INPUT_PULLUP );
  pinMode( BTN_3_PIN, INPUT_PULLUP );

  display.setBrightness(255);
  
}

void loop() {

  checkButtons();

  switch( currentDir ){

    case FORWARD:
      analogWrite( MOTOR_PIN_A, map( speed, 0, 100, MIN_SPEED, MAX_SPEED ) );
      digitalWrite( MOTOR_PIN_B, LOW );
    break;

    case BACKWARD:
      digitalWrite( MOTOR_PIN_A, LOW );
      analogWrite( MOTOR_PIN_B, map( speed, 0, 100, MIN_SPEED, MAX_SPEED ) );
    break;
    
  }

  display.showNumberDec(speed, true);


}
