#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int button1 = 7;
int button2 = 6;
int button3 = 5;

int val1, val2, val3;

int potentiometer1 = 0;
int potentiometer2 = 1;
int potentiometer3 = 2;

void setup() {
    servo1.attach(28);
    servo2.attach(26);
    servo3.attach(24);

    servo1.write(90);
    servo2.write(90);
    servo3.write(90);

    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
}

void loop() {
    turnServo(servo1, val1, button1, potentiometer1);
    turnServo(servo2, val2, button2, potentiometer2);
    turnServo(servo3, val3, button3, potentiometer3);
}

void turnServo(Servo servo, int val, int button, int potentiometer) {
    int buttonState = digitalRead(button);

    if (buttonState == HIGH) {
        val = analogRead(potentiometer);
        val = map(val, 1023, 0, 180, 0);
        servo.write(val);
        delay(15);
    }
}
