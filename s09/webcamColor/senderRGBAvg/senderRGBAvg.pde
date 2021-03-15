  
import processing.video.*;

Capture cam;
import processing.serial.*;

Serial port; 

void setup() {
  size(640, 480);
  
  println(Serial.list());
  String portName = Serial.list()[0];
  port = new Serial(this, portName, 9600);

  // inicjalizacja kamery - "pipeline:autovideosrc" to hack pod win10 jesli Capture nie dziala
  cam = new Capture(this, "pipeline:autovideosrc");
  cam.start();     
      
}

void draw() {
  
  // spr. czy jest nowa klatka
  if (cam.available() == true) {
    cam.read();
  }
  
  // rysujemy obraz z kamery
  image(cam, 0, 0);
  
  // rozmiar obszaru usredniaia koloru
  int sampleBoxW = 100;
  int sampleBoxH = 100;
  
  // usredniony kolor via funkcja extractColorFromImage - vide nizej
  color c = extractColorFromImage( cam.get(width/2-sampleBoxW/2, height/2-sampleBoxH/2, sampleBoxW, sampleBoxH) );
  
  // ryzujemy prevke obszaru usredniania
  fill( c );
  rect(width/2-sampleBoxW/2, height/2-sampleBoxH/2, sampleBoxW, sampleBoxH);
  
  // wysylamy dane na port w formie tekstu - przykladowy komunikat: 255,100,50\n
  // \n koduje znak nowej linii i sygnalizuje koniec komunikatu 
  port.write(int(red(c)) + "," + int(green(c)) + "," + int(blue(c)) + "\n" );
  
}


// funkcja samplujaca wszystkie poksele w obrazku i dajaca info o urednionym kolorze
color extractColorFromImage(final PImage img) {
  img.loadPixels();
  color r = 0, g = 0, b = 0;
 
  for (final color c : img.pixels) {
    r += c >> 020 & 0xFF;
    g += c >> 010 & 0xFF;
    b += c        & 0xFF;
  }
 
  r /= img.pixels.length;
  g /= img.pixels.length;
  b /= img.pixels.length;
 
  return color(r, g, b);
}
