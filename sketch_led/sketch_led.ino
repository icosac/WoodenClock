#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>

const int Button1=6;
const int Button2=7;
const int Button3=8;
const int Button4=9;
const int Sveglia=10;
const int Clock=9;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
RTC_DS3231 rtc;

int timer=0;
int previousHour=-1;
int previousMinute=-1;
int previousSecond=-1;
int prevousDay=0;
int prevousMonth=0;
int timerHour=0;
int timerMin=0;
int temperature=0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(Button4, INPUT);
  pinMode(Sveglia, OUTPUT);
  digitalWrite(Sveglia, LOW);
  pinMode(Clock, OUTPUT);
  digitalWrite(Clock, LOW);
  Serial.print(rtc.now().hour());
  Serial.print("-");
  Serial.print(rtc.now().minute());
  Serial.print("-");
  Serial.println(rtc.now().second());
}

void loop() {
  DateTime RTCtime=rtc.now();
  updateTime(RTCtime);
  if(digitalRead(Button3)==HIGH){
    wannaTimer();
  }
  if(digitalRead(Button4)==HIGH){
    modifyTime();
  }
  if (timerHour==RTCtime.hour()&&timerMinute==RTCtime.minute()){
    setAllarm();
  }
  delay(1000);
}


void setAllarm(){
   
}


int SvegliaState=HIGH;
int count1=0;
int app=0;
bool closing=false;
//Blocca la modifica della sveglia. 
void closeTimer(){
  Serial.print("CHIUDO  ");
  Serial.println(app);
  if (app==1){
    digitalWrite(Sveglia, LOW);
    app=0;
    closing=false;
    count1=0;
  }
  else if (app>1){
    closing=true;   
    app--;
    delay(1000);
    if(digitalRead(Button3)==HIGH){
      closeTimer();
    }
  }
}

//Modifica la sveglia
void wannaTimer(){
  Serial.print("IMPOSTO");
  Serial.println(app);
  if (app==2){
    SvegliaState=HIGH;
    digitalWrite(Sveglia, SvegliaState);
    app++;
  }
  else if (app<2){
    app++;
    delay(1000);
    if(digitalRead(Button3)==HIGH){
      wannaTimer();
    }
  }
  while(app>2||closing){
    if(closing){
      app=3;
    }
    if(count1==9){
      if (SvegliaState==HIGH){
        SvegliaState=LOW;
      }
      else {
        SvegliaState=HIGH;
      }
      digitalWrite(Sveglia, SvegliaState);
      count1=0;
    }
    if(digitalRead(Button1)==HIGH){
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
    if(digitalRead(Button2)==HIGH){
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
    if(digitalRead(Button3)==HIGH){
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
    digitalWrite(Sveglia, LOW);
    app=0;
    closing=false;
    count1=0;
  }
  else if (app>0){
    closing=true;   
    app--;
    delay(1000);
    if(digitalRead(Button4)==HIGH){
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
    if(digitalRead(Button4)==HIGH){
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
        SvegliaState=HIGH;
      }
      digitalWrite(Clock, ClockState);
      count1=0;
    }
    if(digitalRead(Button1)==HIGH){
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
    if(digitalRead(Button2)==HIGH){
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
    if(digitalRead(Button4)==HIGH){
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
  lcd.setCursor(0,0);
  lcd.print(convertIntTo2DigitString(previousHour));
  lcd.print(":");
  lcd.print(convertIntTo2DigitString(previousMinute));
  lcd.print(":");
  lcd.print(convertIntTo2DigitString(previousSecond));
  lcd.print("  ");
  lcd.print(convertIntTo2DigitString(temperatura));
  lcd.print("^C")
  lcd.setCursor(0,1);
  lcd.print(" ");
  lcd.print(convertIntTo2DigitString(preoviouDay)); 
  lcd.print("/");
  lcd.print(convertIntTo2DigitString(preoviouMonth)); 
  lcd.print("    ");
  lcd.print(convertIntTo2DigitString(timerHour));
  lcd.print(":");
  lcd.print(convertIntTo2DigitString(timerHour));
}

void updateTime(DateTime RTCtime){
  previousMinute=RTCtime.minute();
  previousHour=RTCtime.hour();
  previousSecond=RTCtime.second();
  previousDay=RTCtime.day();
  previousMonth=RTCtime.month();
}

