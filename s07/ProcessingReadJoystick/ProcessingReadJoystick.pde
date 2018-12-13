import processing.serial.*;

float x = 0;
float y = 0;
boolean b = false;

Serial port;
void setup() {
  size(800, 800);
  printArray(Serial.list());
  port = new Serial(this, "/dev/tty.usbmodem14311", 9600);
}

void draw() {
  //background(128);
  String bufor = "";
  if (port.available() > 0) {
    bufor = port.readStringUntil(10);
  }
  if (bufor != null && bufor.length()>0) {
    //print(bufor);
    String wartosci[] = split(bufor, ";");
    //printArray(wartosci);
    if (wartosci.length==3) {
      x = map(parseInt(wartosci[0]), 0, 1023, 0, width);
      y = map(parseInt(wartosci[1]), 0, 1023, 0, height);
      if(wartosci[2].charAt(0)=='1'){
        b=true;
      }
      else{
        b=false;
      }
    }
  }
  
  if (b) {
    ellipse(x, y, 100, 100);
  } else {
    ellipse(x, y, 10, 10);
  }
}