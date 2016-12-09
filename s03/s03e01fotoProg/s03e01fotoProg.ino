
void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
   int odczyt1 = analogRead(A0);
   delay(20);
   int odczyt2 = analogRead(A0);
   if(abs(odczyt1-odczyt2)>20) 
     Serial.println("ta dam!");  
   delay(50);
}
