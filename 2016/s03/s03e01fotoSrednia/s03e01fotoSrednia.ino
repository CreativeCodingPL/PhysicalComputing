
void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
   int odczyt = 0;
   for(int i = 0; i<100; i++) {
     odczyt = odczyt + analogRead(A0);
     delay(5);
   }
   odczyt = odczyt / 100;
   Serial.println(odczyt);  
   delay(100);
}
