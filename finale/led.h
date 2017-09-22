#ifndef LED_H
#define LED_H

#include<Wire.h>
#include "variables.h"

void print_time(short hh, short mm);
void print_temp(short tt);
void print_hum(short uu);
void flash();
String int2String (short i);

#endif
