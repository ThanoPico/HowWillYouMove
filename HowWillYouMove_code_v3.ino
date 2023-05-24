#include <Servo.h>

const int triggerPin = 13;
const int echoPin = 12;
float dist = 0.0;
const int motorPin = 9;

void setup() {

pinMode(motorPin, OUTPUT);
Serial.begin(9600);

}

void loop() {

delay(2000); 
  dist = 0.01723 * readUltrasonicDistance(13, 12);
  Serial.println("i apostasi einai"); 
  Serial.print(dist);
  
  if (dist < 10.5) {

    digitalWrite(motorPin, HIGH);
  } 
  else {
    digitalWrite(motorPin, LOW);
    
  }



  
}


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
