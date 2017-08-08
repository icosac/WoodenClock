#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
#include "clock.h"
#include "allarm.h"
#include "variables.h"

int timer=0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(ButtonUp, INPUT);
  pinMode(ButtonDown, INPUT);
  pinMode(ButtonAllarm, INPUT);
  pinMode(ButtonClock, INPUT);
  pinMode(Sveglia, OUTPUT);
  digitalWrite(Sveglia, LOW);
  pinMode(Clock, OUTPUT);
  digitalWrite(Clock, LOW);
  Serial.print(rtc.now().hour());
  Serial.print("-");
  Serial.print(rtc.now().minute());
  Serial.print("-");
  Serial.println(rtc.now().second());
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
  delay(1000);
}
