#include <Wire.h>
#include <RTClib.h>
#include "clock.h"
#include "allarm.h"
#include "variables.h"
#include "led.h"
#include "temp.h"

DateTime RTCtime;

void setup() {
  Serial.begin(9600);
  pinMode(ButtonHour, INPUT);
  pinMode(ButtonMin, INPUT);
  pinMode(ButtonAllarm, INPUT);
  pinMode(ButtonClock, INPUT);
  pinMode(ButtonTemp, INPUT);
  pinMode(10, INPUT);
  digitalWrite(10, HIGH);
  // Serial.print(rtc.now().hour());
  // Serial.print("-");
  // Serial.print(rtc.now().minute());
  // Serial.print("-");
  // Serial.println(rtc.now().second());
  if (!(matrix.begin())){
    // Serial.println("Matrix not found");
    while(1);
  }
}

void loop() {
  RTCtime=rtc.now();
  updateTime(RTCtime);
  if(digitalRead(ButtonAllarm)==HIGH){
    wannaTimer();
  }
  if(digitalRead(ButtonClock)==HIGH){
    modifyTime();
  }
  if (ALLARM && (digitalRead(ButtonHour)==HIGH || digitalRead(ButtonMin)==HIGH)){
    matrix.clear();
    print_time(timerHour, timerMin);
    delay(3000);
    matrix.clear();
  }
  if (timerHour==RTCtime.hour() && timerMin==RTCtime.minute() && ALLARM){
    setAllarm();
  }
  if (digitalRead(ButtonTemp)==HIGH){
    showTemp();
  }
//  int analogread=analogRead(BRIGHTNESSCTRL);
//  if (BRIGHTANLG!=analogread && BRIGHTANLG!=120){ //120 is the default value
//    BRIGHTANLG=analogread;
//    LEDBRIGHTNESS=255*analogread/1023;
//  }

  delay(1000);
}
