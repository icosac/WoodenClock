#include "allarm.h"

int SvegliaState=HIGH;
// int count1=0;
int appAllarm=0;
bool closingAllarm=false;

//Blocca la modifica della sveglia.
void closeTimer(){
  Serial.print("CHIUDO  ");
  Serial.println(appAllarm);
  if (appAllarm==1){
    digitalWrite(Sveglia, LOW);
    appAllarm=0;
    closingAllarm=false;
    // count1=0;
  }
  else if (appAllarm>1){
    closingAllarm=true;
    appAllarm--;
    delay(1000);
    if(analogRead(ButtonAllarm)>AN_HIGH){
      closeTimer();
    }
  }
}

//Modifica la sveglia
void wannaTimer(){
  Serial.print("IMPOSTO SVEGLIA ");
  Serial.println(appAllarm);
  if (appAllarm==2){
    SvegliaState=HIGH;
    digitalWrite(Sveglia, SvegliaState);
    appAllarm++;
  }
  else if (appAllarm<2){
    appAllarm++;
    delay(1000);
    if(analogRead(ButtonAllarm)>AN_HIGH){
      wannaTimer();
    }
  }
  while(appAllarm>2||closingAllarm){
    if(closingAllarm){
      appAllarm=3;
    }
    // if(count1==9){
      if (SvegliaState==HIGH){
        SvegliaState=LOW;
      }
      else {
        SvegliaState=HIGH;
      }
      digitalWrite(Sveglia, SvegliaState);
      //count1=0;
    }
    if(analogRead(ButtonUp)>AN_HIGH){
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
    if(analogRead(ButtonDown)>AN_HIGH){
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
    if(analogRead(ButtonAllarm)>AN_HIGH){
      closeTimer();
    }
    // count1++;
    delay(100);
  //}
  appAllarm=0;
}

void setAllarm(){

}
