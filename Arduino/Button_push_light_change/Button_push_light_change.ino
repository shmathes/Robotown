const int green1 = 13; //first Green LED
const int red1 = 12; //first red LED
const int green2 = 11; //second green LED
const int red2 = 9; //second red LED
const int button1 = 8; //1st button
const int button2 = 10;//second button
// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0; 


void setup() {
  pinMode (green1, OUTPUT); //setting the LED to output
  pinMode (red1, OUTPUT); //setting the LED to output
  pinMode (green2, OUTPUT); //setting the LED to output
  pinMode (red2, OUTPUT); //setting the LED to output
  // initialize the pushbutton pin as an input:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  buttonState1 = digitalRead(button1);//read1st
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  
  if (buttonState1 == LOW) {
    
    digitalWrite (green1, LOW); //turn on the LED
    delay (100); //Delay for a short time
    digitalWrite (green1,HIGH); //turn LED off
    
    digitalWrite (green2, LOW); //turn on the LED
    delay (100); //Delay for a short time
    digitalWrite (green2,HIGH); //turn LED off
  }//if
  else{
    
    digitalWrite (red1, LOW); //turn on the LED
    delay (100); //Delay for a short time
    digitalWrite (red1,HIGH); //turn LED off
    
    digitalWrite (red2, LOW); //turn on the LED
    delay (100); //Delay for a short time
    digitalWrite (red2,HIGH); //turn LED off
    
  }//else

}
