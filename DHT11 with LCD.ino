//Goal: Displaying readings from sensors on lcd
//Theme: dht.read to lcd.print

#include <Adafruit_Sensor.h> // includes the library code
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 8 //defines what pin the sensor is connected to

#define DHTTYPE    DHT11 //defines the type of sensor

DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal.h> 
int Contrast=0; 
LiquidCrystal lcd (12, 11, 5, 4, 3, 2); //assigns pins to lcd

void setup() {
  Serial.begin(9600);
 dht.begin(); //initializes sensor
 analogWrite (6, Contrast);
 lcd.begin(16, 2); // sets up the LCD's number of columns and rows

}

void loop() {

float h = dht.readHumidity(); //assigns letter to humdity read

float t = dht.readTemperature(); //assigns letter to temperature read


 lcd.setCursor (1, 0); //assigns what row to print to

 lcd.print("H:");
 lcd.print(h); //dispays humidity on lcd
 lcd.print("  ");
 lcd.print("Temp:");
 lcd.print(t); //dispays temperature on lcd
lcd.print("°C");

}

