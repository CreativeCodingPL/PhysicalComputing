void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(13));
//  int p1 = digitalRead(13);
//  if( p1 == HIGH ) {
//    Serial.println("off");
//  }
//  if( p1 == LOW ) {
//    Serial.println("on");
//  }

}
