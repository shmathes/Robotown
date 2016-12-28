int ledPin = 13;
int ledPin2 = 10;
int ledPin3 = 11;
int motorPin = 3;

const int trigPin = 2;
const int echoPin = 4;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, 1);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
}

void loop() {

  long duration, inches, cm;

  //analogWrite(motorPin, 255);

  
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.println();
  
  if (inches < 35) {
    analogWrite(motorPin, 0);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay(100);
  }
  else  {
    analogWrite(motorPin, 255);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    delay(100);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    delay(100);
  }
}

long microsecondsToInches(long microseconds) {
  //See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  //According to parallax, there are 73.746 microseconds per inch (sound travels 1130 feet per second)
  //This gives the outbound distance, must then divide by 2 to get the distance of the object. 
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  //The speed of sound is 340 m/s or 29 microseconds per centimeter.
  //The ping travels out and back, so to find the correct distance of the object
  //have to halve the distance traveled.
  return microseconds / 29 / 2;
}


