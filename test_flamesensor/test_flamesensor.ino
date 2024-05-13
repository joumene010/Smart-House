
const int FlameSensor = 3; // the number of the flame sensor pin
const int ledPin =  2; // the number of the LED pin

void setup() 
{
  pinMode (FlameSensor, INPUT); //initialize the flame sensor sensor pin as an input:
  pinMode (ledPin, OUTPUT); //initialize the LED pin as an output:
  Serial.begin(9600); 
}

void loop()
{
  int sensorState = digitalRead (FlameSensor); //read the state of the flame sensor sensor value:
  
  if (sensorState == HIGH) //If the flame sensor detect flame, then sensorState is HIGH:
  {
    digitalWrite(ledPin, HIGH); //Turn LED ON
    // Send a HIGH signal to Proteus Logic State component
    Serial.write(0x01);
  }
  
  else  //If the flame sensor not detect flame, then sensorState state is LOW:
  {
    digitalWrite(ledPin, LOW); //Turn LED OFF
        // Send a LOW signal to Proteus Logic State component
    Serial.write(0x00);
  } 
}
