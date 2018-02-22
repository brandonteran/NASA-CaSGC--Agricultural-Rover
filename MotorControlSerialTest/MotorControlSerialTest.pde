
// CONTROLLING OPTIONS 
// '1' = DC motor #1 turning to the left, '2' = DC motor #1 turning to the right 
// '3' = DC motor #2 turning to the left, '4' = DC motor #2 turning to the right
// '5' = Servo #1 turning to the left, '6' = Servo #1 turning to the right  
// '7' = Servo #2 turning to the left, '8' = Servo #2 turning to the right   


import processing.serial.*;

int signal;
int x1 = 300; // initial position of the joystick
int y1 = 300;
int x2 = 300;
int y2 = 300;
int x3 = 300;
int y3 = 300;
int x4 = 300;
int y4 = 300;

Serial serial;

PFont font;


void setup() {
    size(600,600);
   
    String portName = Serial.list()[3];
    serial = new Serial(this, portName, 9600);
    
    //printArray(PFont.list());
    font = createFont("HelveticaNeue-Thin",24);
    textFont(font);
}

void draw() {
  
    background(0);
    
    ellipse(x1,y1,30,30); // the movement of the WHITE circle represents the direction that the motor #1 is moving 
    fill(255,0,0);
    
    ellipse(x2,y2,30,30); // the movement of the RED circle represents the direction that the motor #2 is moving
    fill(0,255,0);
    
    ellipse(x3,y3,30,30);  // the movement of the GREEN circle represents the direction that the servo #1 moving
    fill(0,0,255);
    
    ellipse(x4,y4,30,30); // the movement of the BLUE circle represents the direction that the servo #2 is moving
    fill(247,107,25);
    
    ellipse(300,300,30,30);
    fill(255);
  
    if(keyPressed) {
      
        if (key == 'w') {
          y1 = 300;
          x1 = 100;
          text("Rover moving forward",11,25);
          serial.write('w'); 
          
        } else if (key == 'a') {
          y2 = 300;
          x2 = 500;
          text("Rover turning left",11,25);
          serial.write('a'); 
          
        } else if (key == 'd') {
          y3 = 300;
          x3 = 100;
          text("Rover turning right",11,25);
          serial.write('d');
          
        } else if (key == 's') {
          y4 = 300;
          x4 = 500;
          text("Rover moving backwards",11,25);
          serial.write('s'); 
        }
        
    } else {
        x1 = 300;
        y1 = 300; 
        x2 = 300;
        y2 = 300;
        x3 = 300;
        y3 = 300;
        x4 = 300;
        y4 = 300;
        
        serial.write('0'); //pause signal
    }
}