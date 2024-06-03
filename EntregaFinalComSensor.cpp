#include <Arduino.h>
#include <LiquidCrystal.h>
#include <PirSensor.h>

#define MOTION_SENSOR_PIN DD5 // Entrada do sensor de movimento

float externotemp;
float tempIn;
unsigned long checartemperatura = 5000;
int externotempPin = A1;
int tempPinIn = 0;
int led = 13;

PirSensor motion = PirSensor(MOTION_SENSOR_PIN, 2, false, false); // defini o sensor de movimento

unsigned long ultchecartemperaturaMillis = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  motion.begin(); // Iniciei o Sensor
}


void loop()
{
digitalWrite(led, HIGH);
unsigned long atualMillis = millis();

if (atualMillis - ultchecartemperaturaMillis >= checartemperatura){

  externotempPin = analogRead (externotempPin);
  externotempPin = externotempPin * 0.48828125;
  tempIn = analogRead (tempPinIn);
  tempIn = tempIn * 0.48828125;

  checartemperatura = atualMillis;  

  lcd.clear();
  lcd.setCursor(6,0);
    lcd.print("Ext Temp:");
    lcd.print(externotemp);
    lcd.print("*C");
    lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.print(tempIn);
    lcd.print("*C");

}
  if(motion.sampleValue() >=0) {
    Serial.print("Movimento dectado!"); // Se tiver movimento deve retornar a mensagem
  }


    delay(50);
    digitalWrite(led, LOW);
}