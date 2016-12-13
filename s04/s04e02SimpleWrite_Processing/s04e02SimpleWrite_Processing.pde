import processing.serial.*;
PImage img;
Serial usb;

void setup() 
{
  size(480, 360);
  printArray(Serial.list());
  String[] porty = Serial.list();
  String portName = porty[3];
  usb = new Serial(this, portName, 9600);
  img = loadImage("kotek.jpg");
}

void draw() {
  image(img,0,0);
  color c = get(mouseX,mouseY);
  if (brightness(c)>128) { 
    usb.write('H');
  } 
  else { 
    usb.write('L');
  }
}