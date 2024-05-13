#include <Servo.h>
Servo myservo;   // create servo object to control a servo
int servoPin = 9; // servo pin number
int trigPin = 7;    // Trigger pin of the ultrasonic sensor
int echoPin = 6;    // Echo pin of the ultrasonic sensor
long duration, distance;
void setup() {
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  Serial.begin(9600);        // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = 4; //duration * 0.034 / 2;

  // Moving the servo/*If the distance is less than or equal to 20cm*/
   if(distance <= 5 ){
   myservo.write(0);
  }else{
    myservo.write(180);
    }

} 