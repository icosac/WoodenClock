#include"alarm.h"

short count=3;
short app_hour=0, app_min=0;

void close_alarm(){
    if (count==3){
        if (alarmHour==app_hour && alarmMinute=app_min){
            ALARM=false;
        }
        else {
            alarmHour=app_hour;
            alarmMinute=app_min;
        }
    }
    else {
        count++;
        delay(SECOND);
        if (digitalRead(ButtonAlarm)==HIGH){
            close_alarm();
        }
    }
}

void wanna_alarm(){
    matrix.clear();
    if (count>0){
        count--;
        delay(SECOND);
        if (digitalRead(ButtonAlarm)==HIGH){
            wanna_alarm();
        }
    }
    else {
        flash();
        ALARM=true;
        app_hour=alarmHour;
        app_min=alarmMinute;
        while(count<4){
            count=count>0? 0:count;
            if (digitalRead(ButtonAlarm)==HIGH){
                close_alarm();
            }
            if (digitalRead(ButtonHour)==HIGH){
                if (app_hour==23){
                    app_hour=0;
                }
            }
            if (digitalRead(ButtonMin)==HIGH){
                if (app_min==59){
                    app_min=0;
                    if (app_hour==23){
                        app_hour=0;
                    }
                }
            }
            matrix.clear();
            print_time(app_hour, app_min);
            delay(100);
        }
    }
}

void set_alarm(){
    TMRpcm tmrpcm;
    tmrpcm.speakerPin = Speaker;

    if (!SD.begin(7)) {
        Serial.println("SD fail");
        return;
    }

    tmrpcm.setVolume(4);
    tmrpcm.play("alarm.wav");
    Serial.println(tmrpcm.isPlaying());
    while(tmrpcm.isPlaying()){
        if(digitalRead(Buttonalarm)==HIGH ||
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
