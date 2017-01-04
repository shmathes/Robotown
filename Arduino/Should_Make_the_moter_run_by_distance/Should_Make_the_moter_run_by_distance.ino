#include <Servo.h>    // Use Servo library, included with IDE

Servo myServo;        // Create Servo object to control the servo 

//sensor
#define echoPin 6 // Echo Pin
#define trigPin 5 // Trigger Pin
//#define LEDPin 13 // Onboard LED

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance


void setup() { 
  myServo.attach(3);  // Servo is connected to digital pin 9 
    //sensor
  Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 //pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
} 

void loop() { 


  digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 //digitalWrite(LEDPin, HIGH); 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 //digitalWrite(LEDPin, LOW); 
 }
 if (distance>5){
    myServo.write(180);   // Rotate servo counter clockwise
  delay(2000);          // Wait 2 seconds
  
 }
}
