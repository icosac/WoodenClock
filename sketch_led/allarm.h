#ifndef ALLARM_H
#define ALLARM_H

#include "variables.h"
#include "led.h"

//The following libryries are for playing .wav files
#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>

void closeTimer();
void wannaTimer();
void setAllarm();

#endif
