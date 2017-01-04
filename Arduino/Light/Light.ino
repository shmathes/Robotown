/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 3;     // the number of the pushbutton pin
const int green =  13;      // the number of the LED pin
const int red =  10;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

//sensor
#define echoPin 5 // Echo Pin
#define trigPin 6 // Trigger Pin
//#define LEDPin 13 // Onboard LED

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
  // initialize the green LED pin as an output:
  pinMode(green, OUTPUT);
  // initialize the red LED pin as an output:
  pinMode(red, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  //sensor
  Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 //pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

void loop() {
 // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn red LED off:
    //digitalWrite(red, HIGH);
    // turn green LED on:
    digitalWrite(green, LOW);
    delay (100);
    digitalWrite(green,HIGH);
    delay (100);
    //make the green LED blink
   
  //sensor
  /* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
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
 //making red blink on distance under 5
 if (distance <= 5) {
  digitalWrite(red, LOW);
  delay(100);
  digitalWrite(red,HIGH);
 }
 else{//making red turn off all other times
  digitalWrite(red,HIGH);
 }
 //Delay 50ms before next reading.
 delay(50);
  }
  else {
    // turn green LED off:
    digitalWrite(green, HIGH);
    // turn red LED on:
    //digitalWrite(red, LOW);    
  }
}

