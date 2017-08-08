#include <Wire.h>
#include <RTClib.h>
#include "clock.h"
#include "allarm.h"
#include "variables.h"
#include "led.h"
#include <Adafruit_IS31FL3731.h>

int timer=0;

matrix = Adafruit_IS31FL3731();

void setup() {
  Serial.begin(9600);
  pinMode(ButtonHour, INPUT);
  pinMode(ButtonMin, INPUT);
  pinMode(ButtonAllarm, INPUT);
  pinMode(ButtonClock, INPUT);
  pinMode(ButtonTemp, INPUT);
  Serial.print(rtc.now().hour());
  Serial.print("-");
  Serial.print(rtc.now().minute());
  Serial.print("-");
  Serial.println(rtc.now().second());
  if (!(matrix.begin()){
    Serial.println("Matrix not found");
    while(1);
  }
}

void loop() {
  DateTime RTCtime=rtc.now();
  updateTime(RTCtime);
  print_time(previousHour, previousMinute);
  if(digitalRead(ButtonAllarm)==HIGH){
    wannaTimer();
  }
  if(digitalRead(ButtonClock)==HIGH){
    modifyTime();
  }
  if (timerHour==RTCtime.hour() && timerMin==RTCtime.minute()){
    setAllarm();
  }
  if (digitalRead(ButtonTemp)==HIGH){
    showTemp();
  }
  int analogread=analogRead(BRIGHTNESSCTRL);
  if (BRIGHTANLG!=analogread){
    BRIGHTNESS=255*analogread/1023;
  }
  delay(1000);
}
