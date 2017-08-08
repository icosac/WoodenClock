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
  if(analogRead(ButtonAllarm)>AN_HIGH){
    wannaTimer();
  }
  if(analogRead(ButtonClock)>AN_HIGH){
    modifyTime();
  }
  if (timerHour==rtc.now().hour() && timerMin==rtc.now().minute()){
    setAllarm();
  }
  showTime();
  delay(1000);
}
