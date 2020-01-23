import processing.serial.*;

Serial myPort;
String inString;
int stopSign = 10;

void setup(){
  
  size( 800, 600 );
  
  printArray(Serial.list());
  String portName = Serial.list()[9];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil(stopSign); 
  
  
  
}

void serialEvent(Serial p) { 
  
  //inString = p.readString(); 
  //print( inString );
  //String trimmed = trim( inString );
  //int val = parseInt( trimmed );
  //println( "> " + val / 2 );
  
  // ---- 
  
  inString = p.readString(); 
  print( inString );
  String trimmed = trim( inString );
  String[] values = trimmed.split(",");
  
  for( int i = 0; i < values.length; i++ ){
    println( parseInt(values[i]) );
  }
  
  
  
} 

void draw(){
  
  background(0);
  
}
