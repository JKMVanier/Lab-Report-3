//Goal: Using analog input value to calculate voltage 
//Theme: analog input and calculations

#include <LiquidCrystal.h> // includes the library code
int Contrast=0; 
LiquidCrystal lcd (12, 11, 5, 4, 3, 2); //assigns pins to lcd

void setup() {

analogWrite (6, Contrast);
 lcd.begin(16, 2); // sets up the LCD's number of columns and rows
  Serial.begin(9600);  
  
}
void loop() {
  
  int sensorValue = analogRead (A0); //assigns value to value read from analog pin
  float voltage = sensorValue * (5.0/1023.0); //converts value from 10bits to 5V

  
  lcd.setCursor (0, 0); //assigns what row to print to
  lcd.print ("Voltage: "); 
   lcd.print (voltage); //displays voltage read from analog pin
  lcd.print ("V"); 
  
 
 
}