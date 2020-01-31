#include <NewPing.h>

NewPing sonar(12, 11, 200);

int val1 = 0;
int val2 = 0;
int val3 = 0;

void setup() {
  
  Serial.begin(9600);

}

void loop() {

  int odleglosc = sonar.ping_cm();
  Serial.println( odleglosc );

//  val1 = random(0,100);
//  val2 = random(0,100);
//  val3 = random(0,100);
//
//  Serial.print( val1 );
//  Serial.print( "," );
//  Serial.print( val2 );
//  Serial.print( "," );
//  Serial.println( val3 );
  
  delay(5);
}
