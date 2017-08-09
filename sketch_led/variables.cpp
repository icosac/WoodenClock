#include "variables.h"

extern const int AN_HIGH=799;

const int ButtonHour=5;
const int ButtonMin=6;
const int ButtonTemp=4;
const int ButtonAllarm=3;
const int ButtonClock=2;

const int SDCS=6;
const int SDMOSI=10;
const int SDMISO=9;

const int Speaker=8;

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

int temperature=0;
const int tempSens=A0;

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
