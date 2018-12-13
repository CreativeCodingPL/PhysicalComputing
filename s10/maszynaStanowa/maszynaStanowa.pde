int NAGRYWAM = 0;
int ODTWARZAM = 1;
int CZEKAM = 2;

int tryb = NAGRYWAM;

PVector[] punkty;
int licznik = 0;

void setup() {
  size(800, 800);
  punkty = new PVector[10];
}

void draw() {
  background(255);
  fill(0);
  noStroke();  
  if (tryb == NAGRYWAM) {
    text("NAGRYWAM",10, 20);
  } 
  else if (tryb == ODTWARZAM) {
    text("ODTWARZAM",10, 20);
    noFill();
    stroke(200, 0, 0);
  
    beginShape();
    for (int i=0; i<licznik; i++) {
      vertex(punkty[i].x, punkty[i].y);
    }
    endShape();
    licznik+=1;
    if (licznik==punkty.length) {
      text("CZEKAM",10, 20);
      tryb = CZEKAM;
      licznik = 0;
    }
  }
  else if(tryb==CZEKAM){
    beginShape();
    for (int i=0; i<punkty.length; i++) {
      vertex(punkty[i].x, punkty[i].y);
    }
    endShape();
  }
}
void mousePressed() {
  if (tryb == NAGRYWAM) {
    punkty[licznik] = new PVector(mouseX, mouseY);
    licznik+=1;
    if (licznik==punkty.length) {
      tryb = ODTWARZAM;
      licznik = 0;
    }
  }
  else if(tryb==CZEKAM){
    tryb=NAGRYWAM;
  }
}