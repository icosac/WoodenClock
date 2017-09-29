#include "clock.h"

short counte=4;

void close_modify(){
    matrix.clear();
    while(counte<4 && digitalRead(ButtonClock)==HIGH){
        delay(SECOND);
        counte++;
    }
    flash();
}

void modify_clock(){
    matrix.clear();
    while(counte>0 && digitalRead(ButtonClock)==HIGH){
        counte--;
        delay(SECOND);
    }
    flash();
    while(counte<4){
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
