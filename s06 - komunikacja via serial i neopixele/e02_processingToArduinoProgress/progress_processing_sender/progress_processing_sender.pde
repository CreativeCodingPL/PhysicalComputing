import processing.serial.*;

Serial myPort;

void setup(){
  
  size( 600, 600 );
  
  // anlogicznie jak w przykladzie e01
  printArray( Serial.list() );
  String portName = Serial.list()[11];
  myPort = new Serial(this, portName, 9600);
  
}


void draw(){
  
  byte progress = byte( map( float(mouseX), 0, float(width), 0, 9 ) );
  // mapujemy pozyjcje myszki na zaakres 0-9 i zapisujemy jako bajt
  myPort.write(progress); // wysyłamy pojedynczy bajt na port
  
  background( map( float(mouseX), 0, float(width), 0, 255 ), 0, 0 );
  
}
