import processing.serial.*;
Serial port;

int cols = 4;
int rows = 4;

int lives = 3;
int points = 0;
int maxPoints = 10;

int GAME = 0;
int LOST = 1;
int WON = 2;

int state = GAME;

int frequency = 3000;

PVector current = new PVector(floor(random(cols)), floor(random(rows)));
int lastChange = 0;

void setup() {  
  size(400, 400);
  //printArray(Serial.list());
  port = new Serial(this, "/dev/tty.usbmodem14321", 9600);
}
void draw() {
  background(255);
  if (state==GAME) {
    println("Lives: " + lives +", Points: " + points);
    
    if ( port.available() > 0) {
      int val = port.read()-97; //numer guzika od 0 do 15
      int x = val%cols; // kolumna
      int y = val/cols; // rzad
      if (x == current.x && y == current.y) {
        points=points+1;
        newPoint();
      } else {
        lives = lives-1;
        newPoint();
      }
    }

    if (millis() - lastChange > frequency) {
      lives = lives-1;
      newPoint();
    }

    for (int x=0; x<rows; x++) {
      for (int y=0; y<cols; y++) {
        fill(255);
        if (current.x==x && current.y == y) {
          fill(255, 0, 0);
        }
        rect(x*(width/cols), y*(height/rows), width/cols, height/rows);
      }
    }
    checkResults();
  } else if (state==LOST) {
    fill(0);
    text("GAME OVER", 100, 100);
  } else if (state==WON) {
    fill(0);
    text("YOU WON!", 100, 100);
  }
}
void newPoint() {
  current = new PVector(floor(random(cols)), floor(random(rows)));
  lastChange = millis();
}
void newGame() {
  points = 0;
  lives = 3;
  state = GAME;
}
void keyPressed() {
  newGame();
}
void checkResults() {
  if (lives<=0) {
    state=LOST;
  } else if (points>=maxPoints) {
    state=WON;
  }
}