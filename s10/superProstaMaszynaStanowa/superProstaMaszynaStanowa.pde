boolean rysujeProstokaty = true;
void setup(){
  size(500, 500);
}
void draw(){
  background(255);
 if(rysujeProstokaty){
   rect(width/2.0 - 100, height/2.0 - 100, 200, 200);
 }
 else {
   ellipse(width/2.0, height/2.0, 200, 200);
 }  
}
void keyPressed(){
  rysujeProstokaty = !rysujeProstokaty;
}