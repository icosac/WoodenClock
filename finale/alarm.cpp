#include"alarm.h"

short counter=3;
short app_hour=0, app_min=0;

void close_alarm(){
    matrix.clear();
    while(counter<3 && digitalRead(ButtonAlarm)==HIGH){
        counter++;
        delay(SECOND);
    }
    if (counter==3){
        if (alarmHour==app_hour && alarmMinute==app_min){
            ALARM=false;
        }
        else {
            alarmHour=app_hour;
            alarmMinute=app_min;
        }
        flash();
    }
}

void wanna_alarm(){
    matrix.clear();
    while(counter>0 && digitalRead(ButtonAlarm)==HIGH){
        counter--;
        delay(SECOND);
    }
    flash();
    ALARM=true;
    app_hour=alarmHour;
    app_min=alarmMinute;
    counter=counter==0? counter:3;
    while(counter<3){
        if (digitalRead(ButtonAlarm)==HIGH){
            close_alarm();
            if (!ALARM){
                break;
            }
        }
        if (digitalRead(ButtonHour)==HIGH){
            if (app_hour==23){
                app_hour=0;
            }
            else {
                app_hour++;
            }
        }
        if (digitalRead(ButtonMin)==HIGH){
            if (app_min==59){
                app_min=0;
                if (app_hour==23){
                    app_hour=0;
                }
            }
            else {
                app_min++;
            }
        }
        matrix.clear();
        print_time(app_hour, app_min);
        delay(100);
    }
    matrix.clear();
    print_time(previousHour, previousMinute);
}

void set_alarm(){
    TMRpcm tmrpcm;
    tmrpcm.speakerPin = Speaker;

    if (!SD.begin(7)) {
        //Serial.println("SD fail");
        return;
    }

    tmrpcm.setVolume(4);
    tmrpcm.play("alarm.wav");
    while(tmrpcm.isPlaying()){
        if(digitalRead(ButtonAlarm)==HIGH ||
                digitalRead(ButtonClock)==HIGH ||
                digitalRead(ButtonHour)==HIGH ||
                digitalRead(ButtonMin)==HIGH
                ){
            break;
        }
    }
    ALARM=false;
    tmrpcm.disable();
//  tmrpcm.stopPlayback();
//  delay(18000);
//  digitalWrite(10, LOW);
}
