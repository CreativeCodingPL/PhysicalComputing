
int pinNums[] = {3, 5, 6};
int pinCount = 5;

void setup() {
  for(int i=0;i<pinCount;i++){
    pinMode(pinNums[i], OUTPUT);
  }
}
void loop() {
  for(int i = 0; i<pinCount;i++){
    for(int j=0; j<255; j++){
      analogWrite(pinNums[i], j);
      delay(10);
    }
  }
}

