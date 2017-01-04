// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 3;     // the number of the pushbutton pin
const int green =  13;      // the number of the LED pin
const int red =  10;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
// initialize the green LED pin as an output:
  pinMode(green, OUTPUT);
  // initialize the red LED pin as an output:
  pinMode(red, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
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
  } else {
    // turn green LED off:
    digitalWrite(green, HIGH);
    // turn red LED on:
    //digitalWrite(red, LOW);    
  }
}
