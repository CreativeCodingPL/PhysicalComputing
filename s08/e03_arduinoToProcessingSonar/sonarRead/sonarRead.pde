import processing.serial.*;

Serial myPort;
int distance = 0;

void setup(){
  
  size( 800, 800 );
  
  // anlogicznie jak w przykladzie e01
  printArray( Serial.list() );
  
  String portName = Serial.list()[17];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n'); // - ta metoda powoduje że serialEvent wywoływana bedzie
  // za kazdym razem gdy w buforze natpotkany zostanie bajt kodujący specjalny znak 
  // kodujacy nowa linie - tekstowo zapisywany jako'\n' - to jest ztw. znak konca komunikatu
  // mowiacy nam ze dotarly juz wszystkie bajty kodujacy wlasciwe dane
  
  
}


void draw(){
  
  background( 0 );
  float s = map( distance, 0, 20, 10, 500 ); // mapowanko :)
  ellipse( width/2, height/2, s, s ); // rysowanko
  
}

//
void serialEvent( Serial port ){
 
  String in = port.readString(); // odczytujemy cala zawartosc bufora za jednym razem i przypisujemy do stringa
  distance = parseInt( trim(in) ); // wywalamy wszystkie znaki niealfanumeryczne - spacje, tabulacje, nowe linie i interpretujemy jako jadna wartosc int
  println( distance );
  
}
