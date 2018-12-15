
int pinNums[] = {3, 5, 6, 9, 10};
int pinCount = 5;

void setup() {
  for(int i=0;i<pinCount;i++){
    pinMode(pinNums[i], OUTPUT);
  }
}
void loop() {
  for(int i = 0; i<pinCount;i++){
    digitalWrite(pinNums[i], HIGH);
    delay(100);
  }
  //delay(1000);
  for(int i = pinCount-1; i>=0;i--){
    digitalWrite(pinNums[i], LOW);
    delay(100);
  }
}

