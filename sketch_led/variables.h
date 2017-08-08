#ifndef VARIABLES_H
#define VARIABLES_H

#include <RTClib.h>
#include <Adafruit_IS31FL3731.h>

extern const int AN_HIGH;

extern const int ButtonHour;
extern const int ButtonMin;
extern const int ButtonAllarm;
extern const int ButtonClock;
extern const int ButtonTemp;

extern const int SDCS;
extern const int SDMOSI;
extern const int SDMISO;

extern const int Speaker=8;

extern const int TempSens=A0;

// extern const int Sveglia;
// extern const int Clock;

extern RTC_DS3231 rtc;

extern int previousHour;
extern int previousMinute;
extern int previousSecond;
// extern int previousDay;
// extern int previousMonth;

extern int timerHour;
extern int timerMin;

extern int temperature;

extern Adafruit_IS31FL3731 matrix;
extern int LEDBRIGHTNESS;
extern const int BRIGHTNESSCTRL;

extern bool ALLARM;

String convertIntTo2DigitString(int i);

#endif
