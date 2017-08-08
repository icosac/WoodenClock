#ifndef VARIABLES_H
#define VARIABLES_H

#include <LiquidCrystal.h>
#include <RTClib.h>

extern const int AN_HIGH;
extern const int ButtonUp;
extern const int ButtonDown;
extern const int ButtonAllarm;
extern const int ButtonClock;
extern const int Sveglia;
extern const int Clock;

extern LiquidCrystal lcd;
extern RTC_DS3231 rtc;

extern int previousHour;
extern int previousMinute;
extern int previousSecond;
extern int previousDay;
extern int previousMonth;
extern int timerHour;
extern int timerMin;
extern int temperature;

#endif
