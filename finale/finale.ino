#include "variables.h"
#include "clock.h"
#include "alarm.h"

void show_temp();
void wanna_alarm();
void modify_clock();

void setup(){
    pinMode(ButtonHour, INPUT);
    pinMode(ButtonMin, INPUT);
    pinMode(ButtonTemp, INPUT);
    pinMode(Buttonalarm, INPUT);
    pinMode(ButtonClock, INPUT);
}

short count=0;

void loop(){
    if (count==59999){
        updateTime();
        count=0;
    }
    if(alarm && previousMinute==alarmMinute && previousHour==alarmHour){
        set_alarm();
    }
    if(digitalRead(ButtonTemp)==HIGH){
        show_temp();
    }
    if(digitalRead(ButtonHour)==HIGH|| digitalRead(ButtonMin)==HIGH){
        print_time();
    }
    if(digitalRead(Buttonalarm)==HIGH){
        wanna_alarm();
    }
    if(digitalRead(ButtonClock)==HIGH){
        modify_clock();
    }
    count++;
    delay(1);
}

void updateTime(){ //LASCIATO QUA PER CONVENIENZA
    Datetime date=rtc.now();
    if (date.minute()!=previosMinute){
        previousMinute=date.minute();
    }
    if (date.hour()!=previosHour){
        previousHour=date.hour();
    }
    matrix.clear();
    print_time();
}


#include <DHT.h>
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
