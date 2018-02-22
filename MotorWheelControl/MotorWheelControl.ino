#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);

void setup() {
    Serial.begin(9600);
    AFMS.begin();
}

void loop() {
    String input = "";
     
    while (Serial.available() > 0) {
        input += (char)Serial.read(); // Read in one char at a time
        delay(5); // Delay for 5 ms so the next char has time to be received
    }
     
    
}

void moveRover(string input, ) {
    if (input == "0") {   
        motor1->run(RELEASE);
        motor2->run(RELEASE);
     
    } else if (input == "w") {
       motor1->setSpeed(30);
       motor2->setSpeed(30);
       motor1->run(FORWARD);
       motor2->run(BACKWARD);
       
    } else if (input == "a") {
       motor1->setSpeed(30);
       motor2->setSpeed(30);
       motor1->run(FORWARD);
       motor2->run(FORWARD);
       
    } else if (input == "d") {
       motor1->setSpeed(30);
       motor2->setSpeed(30);
       motor1->run(BACKWARD);
       motor2->run(BACKWARD);
       
    } else if (input == "s") {
       motor1->setSpeed(30);
       motor2->setSpeed(30);
       motor1->run(BACKWARD);
       motor2->run(FORWARD);
    }
}

