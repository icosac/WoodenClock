#include <Wire.h>
#include <RTClib.h>
#include "clock.h"
#include "allarm.h"
#include "variables.h"
#include "led.h"
#include "temp.h"

int timer=0;

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
  if (!(matrix.begin())){
    Serial.println("Matrix not found");
    while(1);
  }
}

void loop() {
  DateTime RTCtime=rtc.now();
  updateTime(RTCtime);
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
  if (BRIGHTANLG!=analogread && BRIGHTANLG!=120){ //120 is the default value
    BRIGHTANLG=analogread;
    LEDBRIGHTNESS=255*analogread/1023;
  }
  previousSecond++;
  delay(1000);
}
