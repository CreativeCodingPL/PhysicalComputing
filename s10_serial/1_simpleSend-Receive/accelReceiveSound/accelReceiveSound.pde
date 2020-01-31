import processing.serial.*;
import processing.sound.*;

SawOsc saw;

Serial myPort;
String inString;
int stopSign = 10;

float[] accelValues = {0.0, 0.0, 0.0};


void setup(){
  
  size( 800, 600 );
  
  printArray(Serial.list());
  String portName = Serial.list()[9];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil( stopSign ); 
  
  saw = new SawOsc(this);
  saw.play();
  
}

void serialEvent(Serial p) { 
  
  inString = p.readString(); 
  print( inString );
  String trimmed = trim( inString );
  String[] values = trimmed.split(",");
  
  if( values.length == 3 ){
    for( int i = 0; i < values.length; i++ ){
      accelValues[i] = parseFloat( values[i] );
    }
  }
  
  
  
} 

void draw(){
  
  background(0);
  
  float amplitude = map(accelValues[0], -180, 180, 1.0, 0.0);
  saw.amp(amplitude);

  float frequency = map(accelValues[1], -180, 180, 20.0, 1000.0);
  saw.freq(frequency);
  
  float panning = map(accelValues[2], -180, 180, -1.0, 1.0);
  saw.pan(panning);
  
  //fill( #0FFFE9 );
  //ellipse( width/2, height/2, val * 5, val * 5 );
  
  printArray(accelValues );
  
  
}
