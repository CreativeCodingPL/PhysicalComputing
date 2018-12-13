void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int i=2; i<7;i++){
    digitalWrite(i, LOW);
  }
  int wart = analogRead(A2)/200;
  Serial.println(wart);
  for(int i=2; i<2+wart;i++){
    digitalWrite(i, HIGH);
  }
}
