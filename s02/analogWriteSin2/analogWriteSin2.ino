void setup() 
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

float k1 = 0;
float k2 = 0;

void loop() 
{
  int jasnosc1 = map(sin(k1)*150, -150, 150, 0, 255);  
  analogWrite(9, jasnosc1); 
  k1 = k1 + 0.01; 

 int jasnosc2 = map(sin(k2)*150, -150, 150, 0, 255);  
  analogWrite(10, jasnosc2); 
  k2 = k2 + 0.011;
  
  delay(1);                                          
}
