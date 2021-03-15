/**
 * oscP5sendreceive by andreas schlegel
 * example shows how to send and receive osc messages.
 * oscP5 website at http://www.sojamo.de/oscP5
 */
 
import oscP5.*;
import netP5.*;
  
OscP5 oscP5;

int values[] = {0,0,0};
int maxValues[] = {390,390,390};


void setup() {
  size(400,200);
  /* start oscP5, listening for incoming messages at port 12000 */
  oscP5 = new OscP5(this,12100);
  rectMode( CENTER );

}


void draw() {
  background(0);  
  
  for( int i = 0; i < values.length; i++ ){ // lecimy przez najnowsze dane uzyskane z serial
   
   float s = map( values[i], 0, maxValues[i], 10, 100 ); // mapowanko
   rect( 100 + i*100, height/2, s, s ); // rysowanko
    
  }
  
}


void oscEvent(OscMessage theOscMessage) {
  /* print the address pattern and the typetag of the received OscMessage */
  print("### received an osc message.");
  print(" addrpattern: "+theOscMessage.addrPattern());
  println(" typetag: "+theOscMessage.typetag());
  
  if(theOscMessage.checkAddrPattern("/adc")==true) {
    /* check if the typetag is the right one. */
    if(theOscMessage.checkTypetag("iii")) {
      /* parse theOscMessage and extract the values from the osc message arguments. */
      
      for( int i = 0; i < 3; i ++ ){
       values[i] = theOscMessage.get(i).intValue();
      }

    }  
  }
  
  
  
}
