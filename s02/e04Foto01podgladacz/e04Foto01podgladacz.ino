
void setup() {
  pinMode(A0, INPUT_PULLUP); //sztuczka, zeby dzialalo bez dodatkowego rezystora na zewnatrz, bo wlaczamy rezystor wewnetrzny
  Serial.begin(9600);
}

void loop() {
  int jasnosc = analogRead(A0);  
  Serial.println(jasnosc); //podgladanie, arduino wysyla dane do komputera szeregowo przez usb
  delay(100); 
}
