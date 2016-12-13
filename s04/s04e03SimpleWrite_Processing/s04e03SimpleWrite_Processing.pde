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
  img = loadImage("gradient.jpg");
}

void draw() {
  image(img, 0, 0, width, height);
  color c = get(mouseX, mouseY);
  int jasnosc = round(brightness(c));
  println(jasnosc);
  usb.write(jasnosc);
}