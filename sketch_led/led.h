#ifndef LED_H
#define LED_H

#include<Wire.h>
#include "variables.h"

void print_time(int hh, int mm);
void print_temp(int tt);
void print_hum(int uu);
void flash();

#endif
