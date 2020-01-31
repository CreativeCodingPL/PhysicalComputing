
int val1 = 0;
int val2 = 0;
int val3 = 0;

void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  Serial.println( random(0,100) );

//  val1 = random(0,100);
//  val2 = random(0,100);
//  val3 = random(0,100);
//
//  Serial.print( val1 );
//  Serial.print( "," );
//  Serial.print( val2 );
//  Serial.print( "," );
//  Serial.println( val3 );
  
  delay(10);
}
