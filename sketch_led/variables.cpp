#include "variables.h"

extern const int AN_HIGH=799;
const int ButtonUp=A1;
const int ButtonDown=A2;
const int ButtonAllarm=A6;
const int ButtonClock=A3;
const int Sveglia=13;
const int Clock=9;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
RTC_DS3231 rtc;

int previousHour=-1;
int previousMinute=-1;
int previousSecond=-1;
int previousDay=0;
int previousMonth=0;
int timerHour=0;
int timerMin=0;
int temperature=0;
