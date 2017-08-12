#include "clock.h"

int appClock=0; //Counts the seconds for the button has been pressed
bool closingClock=false;
int appHour=-1, appMin=-1;

void modifyTime(){
  matrix.clear();
  // Serial.print("CAMBIO ORA ");
  // Serial.println(appClock);
  if (appClock==4){ //If the button has been pressed for 5 seconds (0-4) then change the time
    DateTime old=rtc.now(); //Saves the moment from which starts editing
    appHour=old.hour();
    appMin=old.minute();
    appClock++;
  }
  else if (appClock<4){ //If the button has not been pressed enough just keep going
    appClock++;
    delay(1000);
    if(digitalRead(ButtonClock)==HIGH){
      modifyTime();
    }
  }
  flash();
  while(appClock>4 || closingClock){ //if the button has been pressed enough, and we are ready to go the start editing
    if(closingClock){ //Closing is true when it started to exit the editing mode but then stopped
      appClock=5;
    }
    if(digitalRead(ButtonHour)==HIGH){
      if (appHour==23){
        appHour=0;
      }
      else {
        appHour++;
      }
      // Serial.print(appHour);
      // Serial.print(":");
      // Serial.println(appMin);
    }
    if(digitalRead(ButtonMin)==HIGH){
      if(appMin==59){
        appMin=0;
//        if(appHour==23){
//          appHour=0;
//        }
//        else{
//          appHour++;
//        }
      }
      else{
        appMin++;
      }
      // Serial.print(appHour);
      // Serial.print(":");
      // Serial.println(appMin);
    }
    if(digitalRead(ButtonClock)==HIGH){
      closeTime();
    }
    delay(100);
    matrix.clear();
    print_time(appHour, appMin);
  }
  appClock=0;
  matrix.clear();
}

void closeTime(){
  // Serial.print("CHIUDO CAMBIO ORA ");
  // Serial.println(appClock);
  if (appClock==0){
    DateTime old=rtc.now();
    // Serial.print("old: ");
    // Serial.print(old.hour());
    // Serial.print(":");
    // Serial.println(old.minute());
    rtc.adjust(DateTime(old.year(), old.month(), old.day(), appHour, appMin, old.second()));
    old=rtc.now();
    // Serial.print("new: ");
    // Serial.print(old.hour());
    // Serial.print(":");
    // Serial.println(old.minute());
    appClock=0;
    closingClock=false;
    //count1=0;
  }
  else if (appClock>0){
    closingClock=true;
    appClock--;
    delay(1000);
    if(digitalRead(ButtonClock)==HIGH){
      closeTime();
    }
  }
  matrix.clear();
}

void updateTime(DateTime RTCtime){
  int appHH=RTCtime.hour();
  int appMM=RTCtime.minute();
  previousSecond=RTCtime.second();
  if (previousHour!=appHH){
    previousHour=appHH;
  }
  if (previousMinute!=appMM){
    previousMinute=appMM;
    matrix.clear();
  }
  print_time(previousHour, previousMinute);
}
