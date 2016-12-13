import processing.serial.*;

Serial usb;  // Create object from Serial class

void setup() 
{
  size(200, 200);
  printArray(Serial.list());
  String[] porty = Serial.list();
  String portName = porty[3];
  usb = new Serial(this, portName, 9600);
}

void draw() {
  background(255);
  if (mouseOverRect() == true) {  // If mouse is over square,
    fill(204);                    // change color and
    usb.write('H');              // send an H to indicate mouse is over square
  } 
  else {                        // If mouse is not over square,
    fill(0);                      // change color and
    usb.write('L');              // send an L otherwise
  }
  rect(50, 50, 100, 100);         // Draw a square
}

boolean mouseOverRect() { // Test if mouse is over square
  return ((mouseX >= 50) && (mouseX <= 150) && (mouseY >= 50) && (mouseY <= 150));
}