#include "variables.h"

extern const int AN_HIGH=599;
const int ButtonUp=A1;
const int ButtonDown=A2;
const int ButtonAllarm=A6;
const int ButtonClock=A3;
const int Sveglia=13;
const int Clock=9;
const int tempSens=A0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
RTC_DS3231 rtc;

int previousHour=-1;
int previousMinute=-1;
int previousSecond=-1;
int previousDay=0;
int previousMonth=0;
int timerHour=0;
int timerMin=0;
double temp=0;

int temperature(){
  int read_an=analogRead(tempSens);
  double temp_app=((read_an*0.0048)-0.5)*100;
  Serial.print("Read_an: ");
  Serial.println(read_an);
  Serial.print("Temp: ");
  Serial.println(temp_app);
  if (temp_app<temp-0.5 || temp_app>temp+0.5){
    double app=temp_app-(int)temp_app;
    if(app<0.3){
      temp=(int)temp_app;
    }
    else if (app>0.7){
      temp=(int)temp_app+1;
    }
    else {
      temp=(int)temp_app+0.5;
    }
  }
  return temp;
}

