import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

void setup() 
{
  size(500, 500);
  // String portName = Serial.list()[3];
  printArray(Serial.list());
  myPort = new Serial(this, "/dev/cu.usbmodem14321", 9600);
}

int licznik = 0;
int dx = 0;
int dy = 0;
int dz = 0;
float X = 250;
float Y = 250;
void draw()
{
  if ( myPort.available() > 0) { 
    val = myPort.read();       
    licznik++;
    if (val == 255) licznik = 0; //startujemy od poczatku paczki RGB
    if (licznik == 1) dx = val-127;
    if (licznik == 2) dy = val-127;
    if (licznik == 3) dz = val-127;
  }
  
  background(255);            
  strokeWeight(10);
  point(X,Y);
  X = X + dx*0.1;
  Y = Y - dy*0.1;
  X = constrain(X, 0, 500);
  Y = constrain(Y, 0, 500);
  println(dx," ",dy," ",dz);
}