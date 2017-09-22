#include "variables.h"

// const short SDCS=7;
// const short SDMOSI=11;
// const short SDMISO=12;
// const short SDCLK=13;

// const short Sveglia=13;
// const short Clock=9;

RTC_DS3231 rtc;

short previousHour=-1;
short previousMinute=-1;
short previousSecond=-1;
// short previousDay=0;
// short previousMonth=0;
short alarmHour=0;
short alarmMinute=0;

short temperature=-253;
short humidity=0;

Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();;
// short LEDBRIGHTNESS=30;

bool ALARM=false;
