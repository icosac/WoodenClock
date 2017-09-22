#ifndef ALARM_H
#define ALARM_H

#include "variables.h"
#include "led.h"

#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>

void wanna_alarm();
void close_alarm();
void set_alarm();

#endif
