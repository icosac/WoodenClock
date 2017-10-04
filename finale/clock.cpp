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
    if (counte==0){
        while(counte<4){
            counte=0;
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
                if (counte==4)
                    break;
            }
            matrix.clear();
            print_time(true, previousHour, previousMinute);
            delay(100);          
        }
        matrix.clear();
        DateTime old=rtc.now();
        rtc.adjust(DateTime(old.year(), old.month(), old.day(), previousHour, previousMinute, old.second()));
    }
    else {
        counte==4;       
    }
    print_time(true, previousHour, previousMinute);   
}
