#ifndef VARIABLES_H
#define VARIABLES_H

#include <RTClib.h>
#include <Adafruit_IS31FL3731.h>

#define SECOND 1000

#define ButtonHour 2
#define ButtonMin 3
#define ButtonTemp 4
#define ButtonAlarm 6
#define ButtonClock 5

// extern  const short SDCS;
// extern  const short SDMOSI;
// extern  const short SDMISO;
// extern  const short SDCLK;

#define Speaker 9;

// extern  const short Sveglia;
// extern  const short Clock;

extern RTC_DS3231 rtc;

extern short previousHour;
extern short previousMinute;
extern short previousSecond;
// extern short previousDay;
// extern short previousMonth;

extern short alarmHour;
extern short alarmMinute;

extern short temperature;
extern short humidity;
extern short previousHour;
extern short previousMinute;
extern short previousSecond;
// extern short previousDay;
// extern short previousMonth;

extern short timerHour;
extern short timerMin;

extern short temperature;
extern short humidity;
#define tempSens 8
#define DHTTYPE 22

extern Adafruit_IS31FL3731 matrix;
#define LEDBRIGHTNESS 30
// extern const short BRIGHTNESSCTRL;
//extern short BRIGHTANLG;

extern bool ALARM;

#endif
