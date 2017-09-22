#ifndef VARIABLES_H
#define VARIABLES_H

#include <RTClib.h>
#include <Adafruit_IS31FL3731.h>

#define SECOND 1000

#define ButtonHour 2
#define ButtonMin 3
#define ButtonTemp 4
<<<<<<< HEAD
#define ButtonAlarm 6
=======
#define Buttonalarm 6
>>>>>>> c541179cb7c3b156bbfc9548afae66ed594f0c5b
#define ButtonClock 5

// extern  const short SDCS;
// extern  const short SDMOSI;
// extern  const short SDMISO;
// extern  const short SDCLK;

#define Speaker 9;

// extern  const short Sveglia;
// extern  const short Clock;

extern RTC_DS3231 rtc;

<<<<<<< HEAD
extern short previousHour;
extern short previousMinute;
extern short previousSecond;
// extern short previousDay;
// extern short previousMonth;

extern short alarmHour;
extern short alarmMinute;

extern short temperature;
extern short humidity;
=======
extern int previousHour;
extern int previousMinute;
extern int previousSecond;
// extern int previousDay;
// extern int previousMonth;

extern int timerHour;
extern int timerMin;

extern int temperature;
extern int humidity;
>>>>>>> c541179cb7c3b156bbfc9548afae66ed594f0c5b
#define tempSens 8
#define DHTTYPE 22

extern Adafruit_IS31FL3731 matrix;
#define LEDBRIGHTNESS 30
//// extern const short BRIGHTNESSCTRL;
<<<<<<< HEAD
//extern short BRIGHTANLG;

extern bool ALARM;
=======
//extern int BRIGHTANLG;

extern bool alarm;

String convertIntTo2DigitString(int i);
>>>>>>> c541179cb7c3b156bbfc9548afae66ed594f0c5b

#endif
