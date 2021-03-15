import processing.serial.*;

import processing.sound.*;
Amplitude amp;
AudioIn in;

Serial port;


color c1 = #08ECFF;
color c2 = #FF035F;

void setup() {
  
  size(640, 360);
  
  println(Serial.list());
  String portName = Serial.list()[0];
  port = new Serial(this, portName, 9600);
  
  // tworzymu obiekty do oblslugi dzwieku
  amp = new Amplitude(this);
  in = new AudioIn(this, 0);
  in.start();
  amp.input(in);
  
}      

void draw() {
  
  float val = map( amp.analyze(), 0, 0.3, 0, 1 );
  val = constrain( val, 0, 1 );
  
  int count = int( 9 * val );
  int brightness = int( 255 * val );
  
  port.write(count + "," +brightness + "\n" );
  
  println(count + "," +brightness);
  
  
}
