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

String convertshortTo2DigitString(short i)  {
  String s = String(i);
  if (i < 10)  {
    s = '0'+s;
  }
  return s;
}

// #include "variables.h"
//
// const int ButtonHour=2;
// const int ButtonMin=3;
// const int ButtonTemp=4;
// const int Buttonalarm=6;
// const int ButtonClock=5;
//
// // const int SDCS=7;
// // const int SDMOSI=11;
// // const int SDMISO=12;
// // const int SDCLK=13;
//
// const int Speaker=9;
//
// // const int Sveglia=13;
// // const int Clock=9;
//
// RTC_DS3231 rtc;
//
// int previousHour=-1;
// int previousMinute=-1;
// int previousSecond=-1;
// // int previousDay=0;
// // int previousMonth=0;
// int timerHour=0;
// int timerMin=0;
//
// int temperature=-253;
// int humidity=0;
// const int tempSens=8;
// const int DHTTYPE=22;
//
// Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();;
// int LEDBRIGHTNESS=30;
// //const int BRIGHTNESSCTRL=A1;
// //int BRIGHTANLG=120;
//
// bool alarm=false;
//
// String convertIntTo2DigitString(int i)  {
//   String s = String(i);
//   if (i < 10)  {
//     s = '0'+s;
//   }
//   return s;
// }
