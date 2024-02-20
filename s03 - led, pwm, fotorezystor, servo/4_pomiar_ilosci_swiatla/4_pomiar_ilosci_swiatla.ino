void setup() {
  pinMode( 9, OUTPUT); // wbudowana dioda led
  pinMode(A1, INPUT_PULLUP); // czujnik jasności
  Serial.begin(9600);
}

void loop() {

  int jasnosc = map( analogRead(A1), 0, 1023, 255, 0);
  
  analogwrite(9, jasnosc);
  
  Serial.print( analogRead(A1) );
  Serial.print( " -> ");
  Serial.println(jasnosc);

  delay(10);
}