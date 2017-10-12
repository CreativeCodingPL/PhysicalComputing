import processing.serial.*;

Serial usb;
int val;
PImage cat;

void setup() 
{
  size(800, 300);
  frameRate(120);
  printArray(Serial.list());
  String portName = Serial.list()[3];
  usb = new Serial(this, portName, 9600);
  cat = loadImage("cat.png");
}

void draw()
{
  background(255);
  if ( usb.available() > 0) {
    val = usb.read();
  }
  image(cat,width/2.0, height-val);
  println(val);
}