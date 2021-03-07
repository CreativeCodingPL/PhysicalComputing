import processing.serial.*;

Serial myPort;
boolean state = false;


void setup(){
  
  size( 600, 600 );
  
  // wypisujemy wszystkie dostepne porty w konsoli
  printArray( Serial.list() );
  
  String portName = Serial.list()[17]; // wskazujemy na port pod ktory podpiete jest Arduino - u każdego bedzie to inny numer
  myPort = new Serial(this, portName, 9600); // tworzymy obiekt tyou Serial przekazujac nazwe portu i predkosc komunikacji - uwaga predkosc musi byc taka sama po stronie Ardiuino jak i Processing
  
}


void draw(){
  
  background( state ? 255 : 0 );
  // konstrukcja warunkowa - zmienna logiczna ? jesli prawda : jesi fałsz 
  
}

void mousePressed(){
  myPort.write('H');  // wysyłamy bajt kodujacy litere H
  state = true;
}

void mouseReleased(){
  myPort.write('L');  // wysyłamy bajt kodujacy litere L
  state = false;
}
