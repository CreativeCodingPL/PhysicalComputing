import processing.sound.*;
import processing.serial.*;

Serial myPort;

SoundFile snd0, snd1, snd2, snd3, snd4, snd5;
void setup() {
  size(800, 600);
  printArray( Serial.list() );
  String portName = Serial.list()[8];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil(10);
  snd0 = new SoundFile(this, "01.wav");
  snd1 = new SoundFile(this, "02.wav");
  snd2 = new SoundFile(this, "03.wav");
  snd3 = new SoundFile(this, "04.wav");
  snd4 = new SoundFile(this, "05.wav");
  snd5 = new SoundFile(this, "06.wav");
}

void draw(){
  background( 0 );
}

void serialEvent(Serial port) { 
  
 int ktory  = int( trim(port.readString()) );
 if(ktory == 0){
   snd0.play();
 }
 if(ktory == 1){
   snd1.play();
 }
 if(ktory == 2){
   snd2.play();
 }
 if(ktory == 3){
   snd3.play();
 }
 if(ktory == 4){
   snd4.play();
 }
 if(ktory == 5){
   snd5.play();
 }
 
} 
