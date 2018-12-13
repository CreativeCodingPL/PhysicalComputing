import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

void setup() 
{
  size(200, 200);
  // String portName = Serial.list()[3];
  printArray(Serial.list());
  myPort = new Serial(this, "/dev/cu.usbmodem14311", 9600);
}

int licznik = 0;
int R = 0;
int G = 0;
int B = 0;
void draw()
{
  if ( myPort.available() > 0) { 
    val = myPort.read();       
    licznik++;
    if (val == 255) licznik = 0; //startujemy od poczatku paczki RGB
    if (licznik == 1) R = val;
    if (licznik == 2) G = val;
    if (licznik == 3) B = val;
  }
  
  background(255);            

  fill(R,G,B);                
  rect(50, 50, 100, 100);
  println(R," ",G," ",B);
}