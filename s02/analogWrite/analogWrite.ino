
void setup() 
{
  pinMode(9, OUTPUT);
}

void loop() 
{
  analogWrite(9, 255);   
  delay(500);                       
  analogWrite(9, 100);  
  delay(500);                       
  analogWrite(9, 30);  
  delay(500);                       
}
