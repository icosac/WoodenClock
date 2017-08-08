#include "clock.h"

int appClock=0; //Counts the seconds for the button has been pressed
int count1Ck=0;
bool closingClock=false;
int appHour=-1, appMin=-1;
int ClockState=HIGH;

void modifyTime(){
  Serial.print("CAMBIO ORA ");
  Serial.println(appClock);
  if (appClock==4){ //If the button has been pressed for 5 seconds (0-4) then change the time
    ClockState=HIGH;
    digitalWrite(Clock, ClockState);
    DateTime old=rtc.now(); //Saves the moment from which starts editing
    appHour=old.hour();
    appMin=old.minute();
    appClock++;
  }
  else if (appClock<4){ //If the button has not been pressed enough just keep going
    appClock++;
    delay(1000);
    if(analogRead(ButtonClock)>AN_HIGH){
      modifyTime();
    }
  }
  while(appClock>4 || closingClock){ //if the button has been pressed enough, and we are ready to go the start editing
    if(closingClock){ //Closing is true when it started to exit the editing mode but then stopped
      appClock=5;
      closingClock=false;
    }
    if(count1Ck==9){
      if (ClockState==HIGH){
        ClockState=LOW;
      }
      else {
        ClockState=HIGH;
      }
      digitalWrite(Clock, ClockState);
      count1Ck=0;
      showTime('c', appHour, appMin);
    }
    if(analogRead(ButtonUp)>AN_HIGH){
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
    if(analogRead(ButtonDown)>AN_HIGH){
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
    if(analogRead(ButtonClock)>AN_HIGH){
      closeTime();
    }
    count1Ck++;
    delay(100);
  }
  appClock=0;
}

void closeTime(){
  Serial.print("CHIUDO CAMBIO ORA ");
  Serial.println(appClock);
  if (appClock==0){
    DateTime old=rtc.now();
    Serial.print("old: ");
    Serial.print(old.hour());
    Serial.print(":");
    Serial.println(old.minute());
    rtc.adjust(DateTime(old.year(), old.month(), old.day(), appHour, appMin, old.second()));
    old=rtc.now();
    Serial.print("new: ");
    Serial.print(old.hour());
    Serial.print(":");
    Serial.println(old.minute());
    digitalWrite(Sveglia, LOW);
    appClock=0;
    closingClock=false;
    //count1Ck=0;
  }
  else if (appClock>0){
    closingClock=true;
    appClock--;
    delay(1000);
    if(analogRead(ButtonClock)>AN_HIGH){
      closeTime();
    }
  }
}

String convertIntTo2DigitString(int i)  {
  String s = String(i);
  if (i < 10)  {
    s = '0'+s;
  }
  return s;
}

void showTime(){
  updateTime();
  lcd.setCursor(0,0);
  lcd.print(convertIntTo2DigitString(previousHour));
  lcd.print(":");
  lcd.print(convertIntTo2DigitString(previousMinute));
  lcd.print(":");
  lcd.print(convertIntTo2DigitString(previousSecond));
  lcd.print("  ");
  lcd.print(temperature());
  lcd.print("^C");
  lcd.setCursor(0,1);
  lcd.print(" ");
  lcd.print(convertIntTo2DigitString(previousDay));
  lcd.print("/");
  lcd.print(convertIntTo2DigitString(previousMonth));
  lcd.print("    ");
  lcd.print(convertIntTo2DigitString(timerHour));
  lcd.print(":");
  lcd.print(convertIntTo2DigitString(timerHour));
}

void showTime(char c, int hh, int mm){
  updateTime();
  lcd.setCursor(0,0);
  if (c=='c'){   
    lcd.print(convertIntTo2DigitString(hh));
    lcd.print(":");
    lcd.print(convertIntTo2DigitString(mm));
  } else { 
    lcd.print(convertIntTo2DigitString(previousHour));
    lcd.print(":");
    lcd.print(convertIntTo2DigitString(previousMinute));
  }
  lcd.print(":");
  lcd.print(convertIntTo2DigitString(previousSecond));
  lcd.print("  ");
  lcd.print(convertIntTo2DigitString(temperature()));
  lcd.print("^C");
  lcd.setCursor(0,1);
  lcd.print(" ");
  lcd.print(convertIntTo2DigitString(previousDay));
  lcd.print("/");
  lcd.print(convertIntTo2DigitString(previousMonth));
  lcd.print("    ");
  if(c=='a'){
    lcd.print(convertIntTo2DigitString(hh));
    lcd.print(":");
    lcd.print(convertIntTo2DigitString(mm));
  }
  else {
    lcd.print(convertIntTo2DigitString(timerHour));
    lcd.print(":");
    lcd.print(convertIntTo2DigitString(timerHour));
  }
}

void updateTime(){
  previousMinute=rtc.now().minute();
  previousHour=rtc.now().hour();
  previousSecond=rtc.now().second();
  previousDay=rtc.now().day();
  previousMonth=rtc.now().month();
}
