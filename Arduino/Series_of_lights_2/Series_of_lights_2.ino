const int green1 = 13; //first Green LED
const int red1 = 12; //first red LED
const int green2 = 11; //second green LED
const int red2 = 9; //second red LED

void setup() {
  pinMode (green1, OUTPUT); //setting the LED to output
  pinMode (red1, OUTPUT); //setting the LED to output
  pinMode (green2, OUTPUT); //setting the LED to output
  pinMode (red2, OUTPUT); //setting the LED to output
}

void loop() {
  digitalWrite (green1, LOW); //turn on the LED
  delay (100); //Delay for a short time
  digitalWrite (green1,HIGH); //turn LED off
  
  digitalWrite (red2, LOW); //turn on the LED
  delay (100); //Delay for a short time
  digitalWrite (red2,HIGH); //turn LED off
  
  digitalWrite (red1, LOW); //turn on the LED
  delay (100); //Delay for a short time
  digitalWrite (red1,HIGH); //turn LED off

  digitalWrite (green2, LOW); //turn on the LED
  delay (100); //Delay for a short time
  digitalWrite (green2,HIGH); //turn LED off

  digitalWrite (green1, LOW); //turn on the LED
  delay (100); //Delay for a short time
  digitalWrite (green1,HIGH); //turn LED off
  
  digitalWrite (red2, LOW); //turn on the LED
  delay (100); //Delay for a short time
  digitalWrite (red2,HIGH); //turn LED off  

}
