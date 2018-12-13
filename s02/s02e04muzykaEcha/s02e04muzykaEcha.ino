int Trig = 2;  //pin 2 Arduino połączony z pinem Trigger czujnika
int Echo = 3;  //pin 3 Arduino połączony z pinem Echo czujnika
int CM;        //odległość w cm
long CZAS;     //długość powrotnego impulsu w uS
 
void setup()
{
                       //inicjalizaja monitora szeregowego
  pinMode(Trig, OUTPUT);                     //ustawienie pinu 2 w Arduino jako wyjście
  pinMode(Echo, INPUT);                      //ustawienie pinu 3 w Arduino jako wejście
  pinMode(7, OUTPUT); 
}
  
void loop()
{
  pomiar_odleglosci();   //pomiar odległości
  CM = constrain(CM, 0, 250);
  int ton = map(CM, 0, 250, 1500, 200); 
  tone(7, ton); 
  delay(200);
}
  
void pomiar_odleglosci ()
{
  digitalWrite(Trig, HIGH);       //ustawienie stanu wysokiego na 10 uS - impuls inicjalizujacy - patrz dokumentacja
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  CZAS = pulseIn(Echo, HIGH);
  CM = CZAS / 58;                //szerokość odbitego impulsu w uS podzielone przez 58 to odleglosc w cm - patrz dokumentacja
}
