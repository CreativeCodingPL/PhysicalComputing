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
int x = 0;
int y = 0;
int z = 0;
void draw()
{
  if ( myPort.available() > 0) { 
    val = myPort.read();       
    licznik++;
    if (val == 255) licznik = 0; //startujemy od poczatku paczki RGB
    if (licznik == 1) x = val-127;
    if (licznik == 2) y = val-127;
    if (licznik == 3) z = val-127;
  }
  
  background(255);            

  line(250, 250, 250+x, 250+y);
  println(x," ",y," ",z);
}