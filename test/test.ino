

#include <LiquidCrystal.h>
#include <Servo.h>
#include "DHT.h"

#define MQPin A2
#define FlameSensor A1
#define redled A3
#define pinkled A4
#define buzzer A5
Servo servo_1; 
Servo servo_2;  // create servo object to control a servo

#define trigPin 7    // Trigger pin of the ultrasonic sensor
#define echoPin 6 // Echo pin of the ultrasonic sensor
long duration, distance;
#define DHTPIN A0
// LCD module connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11       // DHT11 sensor is used
DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT library
char temperature[] = "Temp = 00.0 C  ";
char humidity[]    = "RH   = 00.0 %  ";
#define rfidPin 10


void setup() {
  //flame and gas sensor
  pinMode(MQPin, INPUT_PULLUP);
  pinMode (FlameSensor, INPUT); 
  pinMode (redled, OUTPUT); 
  pinMode (pinkled, OUTPUT); 
  pinMode(buzzer, OUTPUT);

  //ultrasonic sensor
  servo_1.attach(8);  // attaches the servo on pin 9 to the servo object
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input

 //dht11
  lcd.begin(16, 2);
  dht.begin();
  Serial.begin(9600);

  //RFID
  servo_2.attach(9);
  pinMode(rfidPin, INPUT); 
   
}

void loop() {
//flame and gas sensor
int gas_value = digitalRead(MQPin);
int sensorState = digitalRead (FlameSensor); 
//control buzzer
if((gas_value==HIGH) || (sensorState == HIGH))
{
  digitalWrite(buzzer, HIGH);
}
else
{
 digitalWrite(buzzer, LOW); 
}
//control leds
//gas led
if (gas_value==HIGH){
   digitalWrite(pinkled, HIGH);
}else{
   digitalWrite(pinkled, LOW);
}
//flame led
if (sensorState == HIGH){
   digitalWrite(redled, HIGH);
}else{
   digitalWrite(redled, LOW);
}

//ultrasonic sensor
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
  distance = 20; //duration * 0.034 / 2;

  // Moving the servo/*If the distance is less than or equal to 20cm*/
   if(distance <= 20 ){
   servo_1.write(40);
  }else{
   servo_1.write(180);
    }
  
  //dht11
   // Read humidity
  byte RH = dht.readHumidity();
  //Read temperature in degree Celsius
  byte Temp = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again)
  if (isnan(RH) || isnan(Temp)) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Error");
    return;
  }

  temperature[7]     = Temp / 10 + 48;
  temperature[8]     = Temp % 10 + 48;
  temperature[11]    = 223;
  humidity[7]        = RH / 10 + 48;
  humidity[8]        = RH % 10 + 48;
  lcd.setCursor(0, 0);
  lcd.print(temperature);
  lcd.setCursor(0, 1);
  lcd.print(humidity);
  delay(500);
  lcd.clear();

  //RFID
  
  int rfidState = digitalRead(rfidPin); 
  if (rfidState == HIGH) { 
    servo_2.write(180);     
            
  }
  else if (rfidState == LOW ) { 
    servo_2.write(0);      
         

  }}