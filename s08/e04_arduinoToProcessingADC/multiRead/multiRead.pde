import processing.serial.*;

Serial myPort;
int values[] = {0,0,0};
int maxValues[] = {390,390,390};

void setup(){
  
  size( 800, 800 );
  
  // vide przyklad e01
  printArray( Serial.list() );
  String portName = Serial.list()[17];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n'); 
  
}


void draw(){
  
  background( 0 );
  
  for( int i = 0; i < values.length; i++ ){ // lecimy przez najnowsze dane uzyskane z serial
   
   float s = map( values[i], 0, maxValues[i], 10, 100 ); // mapowanko
   ellipse( 100 + i*100, height/2, s, s ); // rysowanko
    
  }
  

  
}

// uwaga - serialEvent wywołuje sie "asynchronicznie" do draw - moze byc np. wywolana miedzy klatkami albo w trakcie
// dlatego dane ktore tu odczytujemy nalezy przechwywac w globalnych zmiennych by moc z nich korzystac w draw
void serialEvent( Serial port ){
 
  String in = trim(port.readString());
  String valuesInput[] = split(in,','); // metoda split, zamienia nam tekst na tablice stringow - tu przyjmujemy przecinek jako miejsce ciecia
  
  for( int i = 0; i < valuesInput.length; i++ ){ // petla leci przez wszystkie wartosc tekstowe
    values[i] = parseInt( valuesInput[i] ); // kazda z nikch interpretujemy jako int i wkladamy do globalnej tablicy values, ktorej uzywamy w draw
  }
  
  printArray( valuesInput ); // wypisujemy tablice
  
  
}
