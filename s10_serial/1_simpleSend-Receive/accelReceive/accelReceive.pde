import processing.serial.*;

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
  
  //fill( #0FFFE9 );
  //ellipse( width/2, height/2, val * 5, val * 5 );
  
  //printArray(accelValues );
  
  
  
}
