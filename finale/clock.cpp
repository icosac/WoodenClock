#include "clock.h"

short counte=5;

void close_modify(){
    matrix.clear();
    if (counte<6){
        delay(SECOND);
        if (digitalRead(ButtonClock)==HIGH){
            counte--;
            close_modify();
        }
    }
    flash();
}

void modify_clock(){
    matrix.clear();
    if (counte>0){
        counte--;
        if (digitalRead(ButtonClock)==HIGH){
            delay(SECOND);
            modify_clock();
        }
    }
    else {
        flash();
        while(counte<6){
            counte=counte>0? 0:counte;
            if (digitalRead(ButtonHour)==HIGH){
                if (previousHour==23){
                    previousHour=0;
                }
                else {
                    previousHour++;
                }
            }
            if (digitalRead(ButtonMin)==HIGH){
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
