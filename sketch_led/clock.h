#ifndef CLOCK_H
#define CLOCK_H

#include "variables.h"
#include "led.h"

void closeTime();
void modifyTime();
void showTime(int hh, int mm);
void updateTime(DateTime RTCtime);

#endif
