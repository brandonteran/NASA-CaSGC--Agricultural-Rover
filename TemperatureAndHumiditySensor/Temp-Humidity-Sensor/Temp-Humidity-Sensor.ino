/**********************************************
Thermometer and Humidity on Processing Platform
Project Dear John
http://www.0lab.it
October 2013
Creative Common License
**********************************************/

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht (DHTPIN, DHTTYPE);

int tempPin = 0;
int i;
float samplest[10];
float samplesh[10];

void setup() {
    Serial.begin(9600);
    dht.begin();
}
void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    Serial.print(h);
    Serial.print(" ");
    Serial.println(t);
}
