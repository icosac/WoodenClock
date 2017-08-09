#include "variables.h"

extern const int AN_HIGH=799;

const int ButtonHour=5;
const int ButtonMin=6;
const int ButtonTemp=4;
const int ButtonAllarm=3;
const int ButtonClock=2;

const int SDCS=7;
const int SDMOSI=11;
const int SDMISO=12;
const int SDCLK=13;

const int Speaker=9;

// const int Sveglia=13;
// const int Clock=9;

RTC_DS3231 rtc;

int previousHour=-1;
int previousMinute=-1;
int previousSecond=-1;
// int previousDay=0;
// int previousMonth=0;
int timerHour=0;
int timerMin=0;

int temperature=-253;
int humidity=0;
const int tempSens=8;
const int DHTTYPE=22;

Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();;
int LEDBRIGHTNESS=30;
const int BRIGHTNESSCTRL=A1;
int BRIGHTANLG=120;

bool ALLARM=false;

String convertIntTo2DigitString(int i)  {
  String s = String(i);
  if (i < 10)  {
    s = '0'+s;
  }
  return s;
}
