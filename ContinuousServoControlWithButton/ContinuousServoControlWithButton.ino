#include <Servo.h>

Servo armBaseServo;  

int buttonRight = 50;  
int buttonLeft = 52;

void setup() {
    armBaseServo.attach(9);
    pinMode(buttonLeft, INPUT);
    pinMode(buttonRight, INPUT);  
}

void loop() {
    int buttonLeftState = digitalRead(buttonLeft);
    int buttonRightState = digitalRead(buttonRight);
  
    if (buttonLeftState == HIGH) {
        armBaseServo.write(106);
        delay(50);
    } else if (buttonRightState == HIGH) {
        armBaseServo.write(83);
        delay(50);
    } else {
        armBaseServo.write(93);
        delay(50);
    }
}

