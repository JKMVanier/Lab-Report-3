//Goal: Displaying readings from sensors on lcd
//Theme: dht.read and pulse.In to lcd.print

#include <Adafruit_Sensor.h> // includes the library code
#include <DHT.h>
#include <DHT_U.h>


#define DHTPIN 8 //defines what pin the sensor is connected to

#define DHTTYPE    DHT11 //defines the type of sensor

DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal.h> 
int Contrast=0; 
LiquidCrystal lcd (12, 11, 5, 4, 3, 2); //assigns pins to lcd

#define trigPin 10 //assigns trig pin
#define echoPin 13 // assigns echo pin 

float duration, distance; 

void setup() {
  Serial.begin(9600);
 dht.begin(); //initializes sensor
 analogWrite (6, Contrast);
 lcd.begin(16, 2); // sets up the LCD's number of columns and rows

pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);

}

void loop() {

float h = dht.readHumidity(); //assigns letter to humdity read

float t = dht.readTemperature(); //assigns letter to temperature read


 lcd.setCursor (1, 0);  //assigns what row to print to

 lcd.print("H:");
 lcd.print(h); //dispays humidity on lcd
 lcd.print("  ");
 lcd.print("Temp:"); //dispays temperature on lcd
 lcd.print(t);
lcd.print("°C");


// generate 2-microsecond pulse to trig pin
digitalWrite(trigPin, LOW); 
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(2);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH); // measures duration of pulse from echo pin

distance = (duration/2) * 0.0343;  // calculates the distance (Speed of sound wave divided by 2 (go and back))

lcd.setCursor (0, 1); //assigns what row to print to


lcd.print("Distance:"); //indicates if the object is too far away from sensor on lcd
if (distance >= 400 && distance <= 2){
lcd.print("Too far"); 
}
else{
lcd.print(distance); //dispays distance on lcd
lcd.print("cm");
delay(500);
}

}

