#include <SerialCommand.h>

SerialCommand sCmd;
int r = 0;
int g = 0;
int b = 0;

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

void setup() {

  pinMode( RED_PIN, OUTPUT );
  pinMode( GREEN_PIN, OUTPUT );
  pinMode( BLUE_PIN, OUTPUT );
  
  Serial.begin(9600);
  
  sCmd.addCommand("LED", ledColor);
  
}

void loop() {
  
  sCmd.readSerial();

  analogWrite( RED_PIN, r );
  analogWrite( GREEN_PIN, g );
  analogWrite( BLUE_PIN, b );
  
}

void ledColor() {

  char *arg;
  
  arg = sCmd.next();    
  if (arg != NULL) {
    r = atoi(arg);
  }

  arg = sCmd.next();    
  if (arg != NULL) {
    g = atoi(arg);
  }

  arg = sCmd.next();    
  if (arg != NULL) {
    b = atoi(arg);
  }
    
}

