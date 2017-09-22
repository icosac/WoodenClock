#include "variables.h"
#include "clock.h"
#include "alarm.h"
#include "led.h"
#include <DHT.h>

void updateTime(){ //LASCIATO QUA PER CONVENIENZA
    DateTime date=rtc.now();
    if (date.minute()!=previousMinute){
        previousMinute=date.minute();
    }
    if (date.hour()!=previousHour){
        previousHour=date.hour();
    }
    matrix.clear();
    print_time(previousHour, previousMinute);
}

void showTemp(){
  DHT dht(tempSens, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

  dht.begin();

  humidity=dht.readHumidity();
  temperature=dht.readTemperature();

  // Serial.print("Temperatura: "); // Serial.println(temperature);
  // Serial.print("Umidità: "); // Serial.println(humidity);
  matrix.clear();
  print_temp(temperature>-1?temperature:0);
  delay(3000);
  matrix.clear();
  print_hum(humidity);
  delay(2000);
  matrix.clear();
}

void setup(){
    pinMode(ButtonHour, INPUT);
    pinMode(ButtonMin, INPUT);
    pinMode(ButtonTemp, INPUT);s
    pinMode(ButtonAlarm, INPUT);
    pinMode(ButtonClock, INPUT);
    if (!(matrix.begin())){
        while(1);
    }
}

short count=1;

void loop(){
    if (count==6*SECOND){
        updateTime();
        count=1;
    }
    if (count==SECOND/2){
        matrix.clear();
        print_time(previousHour, previousMinute);
    }
    if(ALARM && previousMinute==alarmMinute && previousHour==alarmHour){
        set_alarm();
    }
    if(digitalRead(ButtonTemp)==HIGH){
        showTemp();
    }
    if(digitalRead(ButtonHour)==HIGH|| digitalRead(ButtonMin)==HIGH){
        print_time(alarmHour, alarmMinute);
    }
    if(digitalRead(ButtonAlarm)==HIGH){
}
