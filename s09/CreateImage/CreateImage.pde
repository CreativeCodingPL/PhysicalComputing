PGraphics img;

void setup() {
  size(500, 500);  
  img = createGraphics(300,300);
  img.beginDraw();
  img.background(0);
  stroke(255,0,0);
  strokeWeight(3);
}

void draw() {
  img.beginDraw();
  if(mousePressed) {
   img.ellipse(mouseX,mouseY,100,100);
   image(img, 0,0);
  }
  
  img.endDraw();
  line(mouseX-10, mouseY, mouseX+10, mouseY);
  line(mouseX, mouseY-10, mouseX, mouseY+10);
  if(keyPressed) {
    img.save("elipsy.jpg");
  }
}