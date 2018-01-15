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

void draw()
{
  if ( myPort.available() > 0) { 
    val = myPort.read();        
  }
  
  background(255);            
  
  fill(val);                
  rect(50, 50, 100, 100);
  println(val);
}