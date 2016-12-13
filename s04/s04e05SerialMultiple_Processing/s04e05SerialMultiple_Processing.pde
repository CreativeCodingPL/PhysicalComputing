import processing.serial.*;

Serial usb;
int[] serialInArray = new int[2];
int serialCount = 0;
boolean firstContact = false;
int val1 = 0;
int val2 = 0;

void setup() {
  size(256, 256);

  printArray(Serial.list());
  String portName = Serial.list()[3];
  usb = new Serial(this, portName, 9600);
}

void draw() {
  background(255);
  ellipse(val1, val2, 20, 20);
}

void serialEvent(Serial myPort) {
  int inByte = myPort.read();
  if (firstContact == false) {
    if (inByte == 'A') { 
      myPort.clear();
      firstContact = true;
      myPort.write('A');
    } 
  } 
  else {
    serialInArray[serialCount] = inByte;
    serialCount++;
    if (serialCount > 1 ) {
      val1 = serialInArray[0];
      val2 = serialInArray[1];
      println(val1 + "\t" + val2);
      myPort.write('A');
      serialCount = 0;
    }
  }
}