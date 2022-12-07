/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
#include "Arduino.h"
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position


int avg_read(int rpin, int samples) {
  float reading = 0; 
  for (int i = 0; i < samples; i++)
  {
    reading += analogRead(rpin); 
  }

  Serial.println((int)(reading/samples));

  return (int)(reading/samples); 



}

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 

}

void loop() {
  delay(avg_read(A6, 10) * 4); 
   
  myservo.write(10); 
  delay(300);

  digitalWrite(LED_BUILTIN, LOW);  
  myservo.write(50);
  delay(100); //Go a tiny bit 
  myservo.write(140); 
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(500);
  myservo.write(40);


  
}