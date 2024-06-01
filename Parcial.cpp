#include <Arduino.h>
#include <LiquidCrystal.h>

float temp;
float tempIn;
int tempPin = 0;
int tempPinIn = 0;
int led = 13;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{

  digitalWrite(led, HIGH);
  
  tempIn = analogRead (tempPinIn);
  tempIn = tempIn * 0.48828125;
  lcd.setCursor(6,0);
    lcd.print("PAC");
    lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.print(tempIn);
    lcd.print("*C");

    delay(5000);

}

