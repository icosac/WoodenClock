#ifndef CLOCK_H
#define CLOCK_H

#include "variables.h"
#include <LiquidCrystal.h>

void closeTime();
void modifyTime();
String convertIntTo2DigitString(int i);
void showTime(int hh, int mm);
void updateTime(DateTime RTCtime);

#endif
