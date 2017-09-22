#include "clock.h"

short count=5;

void close_modify(){
    matrix.clear();
    if (count<6){
        delay(SECOND);
        if (digitalRead(ButtonClock)==HIGH){
            count--;
            close_modify();
        }
    }
    flash();
}

void modify_clock(){
    matrix.clear();
    if (count>0){
        count--;
        if (digitalRead(ButtonClock)==HIGH){
            delay(SECOND);
            modify_clock();
        }
    }
    else {
        flash();
        while(count<6){
            if (digitalRead(ButtonHour)==HIGH){
                if (previousHour==23){
                    previousHour=0;
                }
                else {
                    previousHour++;
                }
            }
            if (digitalRead(ButtonMinute)==HIGH){
                if (previousMinute==59){
                    previousMinute=0;
                }
                else {
                    previousMinute++;
                }
            }
            if (digitalRead(ButtonClock)==HIGH){
                close_modify();
            }
            matrix.clear();
            print_time(previousHour, previousMinute);
            delay(100);
        }
    }
}
