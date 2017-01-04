//collects data from an analog sensor
const int green = 13; // green LED
int sensorpin = 0;                 // analog pin used to connect the sharp sensor
int val = 0;                 // variable to store the values from sensor(initially zero)

void setup()
{
  pinMode(green, OUTPUT); //green set output
  Serial.begin(9600);               // starts the serial monitor
}
 
void loop()
{
  val = analogRead(sensorpin);       // reads the value of the sharp sensor
  Serial.println(val);            // prints the value of the sensor to the serial monitor
  delay(400);                    // wait for this much time before printing next value

  if (val > 100) {
     digitalWrite (green, LOW);
     
  }//if
  else{
    digitalWrite(green, HIGH);
  }//else
}
