#include <Wire.h>
#include <RTClib.h>

const int ZERO=7;
const int UNO=6;
const int DUE=5;
const int TRE=4;
const int QUATTRO=3;
const int ButtonUp=2;
const int ButtonDown=3;
const int ButtonAllarm=4;
const int ButtonClock=5;
const int ButtonAllarm=6;
const int Clock=9;

RTC_DS3231 rtc;

int timer=0;
int previousHour=-1;
int previousMinute = -1;
int timerHour=0;
int timerMin=0;


void setup() {
  Serial.begin(9600);
  rtc.begin();
  pinMode(ButtonUp, INPUT);
  pinMode(ButtonDown, INPUT);
  pinMode(ButtonAllarm, INPUT);
  pinMode(ButtonClock, INPUT);
  pinMode(ButtonAllarm, OUTPUT);
  digitalWrite(ButtonAllarm, LOW);
  pinMode(Clock, OUTPUT);
  digitalWrite(Clock, LOW);
  Serial.print(rtc.now().hour());
  Serial.print("-");
  Serial.print(rtc.now().minute());
  Serial.print("-");
  Serial.println(rtc.now().second());
}

void loop() {
  if(timer==299){
    DateTime RTCtime=rtc.now();
    if(RTCtime.hour()!=previousHour || RTCtime.minute()!=previousMinute){
      updateTime(RTCtime.hour(), RTCtime.minute());
    }
    Serial.print(RTCtime.hour());
    Serial.print("-");
    Serial.print(RTCtime.minute());
    Serial.print("-");
    Serial.println(RTCtime.second());
    timer=0;
  }
  else{
    timer++;
  }
  if(digitalRead(ButtonAllarm)==HIGH){
    wannaTimer();
  }
  if(digitalRead(ButtonClock)==HIGH){
    modifyTime();
  }
  delay(100);
}


int ButtonAllarmState=HIGH;
int count1=0;
int app=0;
bool closing=false;
void closeTimer(){
  Serial.print("CHIUDO  ");
  Serial.println(app);
  if (app==0){
    digitalWrite(ButtonAllarm, LOW);
    app=0;
    closing=false;
    count1=0;
  }
  else if (app>0){
    closing=true;   
    app--;
    delay(1000);
    if(digitalRead(ButtonAllarm)==HIGH){
      closeTimer();
    }
  }
}

void wannaTimer(){
  Serial.print("IMPOSTO  ");
  Serial.println(app);
  if (app==2){
    ButtonAllarmState=HIGH;
    digitalWrite(ButtonAllarm, ButtonAllarmState);
    app++;
  }
  else if (app<2){
    app++;
    delay(1000);
    if(digitalRead(ButtonAllarm)==HIGH){
      wannaTimer();
    }
  }
  while(app>2||closing){
    if(closing){
      app=3;
    }
    if(count1==9){
      if (ButtonAllarmState==HIGH){
        ButtonAllarmState=LOW;
      }
      else {
        ButtonAllarmState=HIGH;
      }
      digitalWrite(ButtonAllarm, ButtonAllarmState);
      count1=0;
    }
    if(digitalRead(ButtonUp)==HIGH){
      if (timerHour==23){
        timerHour=0;
      }
      else {
        timerHour++;
      }
      Serial.print(timerHour);
      Serial.print(":");
      Serial.println(timerMin);
    }
    if(digitalRead(ButtonDown)==HIGH){
      if(timerMin==59){
        timerMin=0;
        if(timerHour==23){
          timerHour=0;
        }
        else{
          timerHour++;
        }
      }
      else{
        timerMin++;
      }
      Serial.print(timerHour);
      Serial.print(":");
      Serial.println(timerMin);
    }
    if(digitalRead(ButtonAllarm)==HIGH){
      closeTimer();
    }
    count1++;
    delay(100);
  }
  app=0;
}

int appHour=-1, appMin=-1;
int ClockState=HIGH;
void closeTime(){
  Serial.print("CHIUDO CAMBIO ORA");
  Serial.println(app);
  if (app==0){
    DateTime old=rtc.now();
    Serial.print("old: ");
    Serial.print(old.hour());
    Serial.print(":");
    Serial.println(old.minute());
    rtc.adjust(DateTime(old.year(), old.month(), old.day(), appHour, appMin, old.second())); 
    old=rtc.now();
    Serial.print("old: ");
    Serial.print(old.hour());
    Serial.print(":");
    Serial.println(old.minute());
    digitalWrite(ButtonAllarm, LOW);
    app=0;
    closing=false;
    count1=0;
  }
  else if (app>0){
    closing=true;   
    app--;
    delay(1000);
    if(digitalRead(ButtonClock)==HIGH){
      closeTime();
    }
  }
}

void modifyTime(){
  Serial.print("CAMBIO ORA");
  Serial.println(app);
  if (app==4){
    ClockState=HIGH;
    digitalWrite(Clock, ClockState);
    DateTime old=rtc.now();
    appHour=old.hour();
    appMin=old.minute();
    app++;
  }
  else if (app<4){
    app++;
    delay(1000);
    if(digitalRead(ButtonClock)==HIGH){
      modifyTime();
    }
  }
  while(app>4||closing){
    if(closing){
      app=5;
    }
    if(count1==9){
      if (ClockState==HIGH){
        ClockState=LOW;
      }
      else {
        ButtonAllarmState=HIGH;
      }
      digitalWrite(Clock, ClockState);
      count1=0;
    }
    if(digitalRead(ButtonUp)==HIGH){
      if (appHour==23){
        appHour=0;
      }
      else {
        appHour++;
      }
      Serial.print(appHour);
      Serial.print(":");
      Serial.println(appMin);
    }
    if(digitalRead(ButtonDown)==HIGH){
      if(appMin==59){
        appMin=0;
        if(appHour==23){
          appHour=0;
        }
        else{
          appHour++;
        }
      }
      else{
        appMin++;
      }
      Serial.print(appHour);
      Serial.print(":");
      Serial.println(appMin);
    }
    if(digitalRead(ButtonClock)==HIGH){
      closeTime();
    }
    count1++;
    delay(100);
  }
  app=0;
}

String convertIntTo2DigitString(int i)  {
  String s = String(i);
  if (i < 10)  {
    s = '0'+s;
  }
  return s;
}

void showTime(int hh, int mm){
  String min = convertIntTo2DigitString(mm);
  String hour = convertIntTo2DigitString(hh);
  
  //matrix.clear();
  //matrix.drawBitmap(0, 0, (byte*)noArray[(int)hour[0]-'0'], 3, 9, LEDBRIGHTNESS);
  //matrix.drawBitmap(4, 0, (byte*)noArray[(int)hour[1]-'0'], 3, 9, LEDBRIGHTNESS);
  //matrix.drawBitmap(9, 0, (byte*)noArray[(int)min[0]-'0'], 3, 9, LEDBRIGHTNESS);
  //matrix.drawBitmap(13, 0, (byte*)noArray[(int)min[1]-'0'], 3, 9, LEDBRIGHTNESS);
}

void updateTime(int hh, int mm){
  previousMinute=mm;
  previousHour=hh;
  showTime(hh, mm);
}

