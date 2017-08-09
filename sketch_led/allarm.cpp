#include "allarm.h"

int SvegliaState=HIGH;
// int count1=0;
int appAllarm=0;
bool closingAllarm=false;

//Blocca la modifica della sveglia.
void closeTimer(){
  Serial.print("CHIUDO  ");
  Serial.println(appAllarm);
  if (appAllarm==1){ //Se ha finito il countdown allora setto tutto alla normalità ed esco
    // digitalWrite(Sveglia, LOW);
    appAllarm=0;
    closingAllarm=false;
    ALLARM=false;
    // count1=0;
  }
  else if (appAllarm>1){ //Altrimenti la funzione si richiama fintanto che il countdown non è finito e si continua a premere il pulsante
    closingAllarm=true;
    appAllarm--;
    delay(1000);
    if(digitalRead(ButtonAllarm)==HIGH){
      closeTimer();
    }
  }
  matrix.clear();
}

//Modifica la sveglia
void wannaTimer(){
  matrix.clear();
  Serial.print("IMPOSTO SVEGLIA ");
  Serial.println(appAllarm);
  if (appAllarm==2){ //Se sono passati due secondi allora entra nel successivo ciclo while
    SvegliaState=HIGH;
    // digitalWrite(Sveglia, SvegliaState);
    appAllarm++;
    ALLARM=true;
  }
  else if (appAllarm<2){ //Altrimenti si richiama ricorsivamente
    appAllarm++;
    delay(1000);
    if(digitalRead(ButtonAllarm)==HIGH){
      wannaTimer();
    }
  }
  flash();
  while(appAllarm>2||closingAllarm){ //Se sono passati due secondi o se si è provato a uscire ma non si è terminato il countdown
     if(closingAllarm){ //Risetto il countdown nel caso in cui si abbia deciso di non uscire
      appAllarm=3;
    }
    // if(count1==9){
    //   if (SvegliaState==HIGH){
    //     SvegliaState=LOW;
    //   }
    //   else {
    //     SvegliaState=HIGH;
    //   }
    //   digitalWrite(Sveglia, SvegliaState);
    //   count1=0;
    // }
    if(digitalRead(ButtonHour)==HIGH){ //Se viene premuto il pulsante dell'ora aumenta l'ora
      if (timerHour==23){
        timerHour=0;
      }
      else {
        timerHour++;
      }
    }
    if(digitalRead(ButtonMin)==HIGH){ //Se viene premuto il pulsante dei minuti aumentano i minuti
      if(timerMin==59){
        timerMin=0;
//        if(timerHour==23){
//          timerHour=0;
//        }
//        else{
//          timerHour++;
//        }
      }
      else{
        timerMin++;
      }
    }
    Serial.print(timerHour);
    Serial.print(":");
    Serial.println(timerMin);
    if(digitalRead(ButtonAllarm)==HIGH){ //Se viene premuto di nuovo il pulsante per la sveglia allora si vuole uscire
      closeTimer();
    }
    matrix.clear();
    print_time(timerHour, timerMin);
    delay(100);
  }
  appAllarm=0;
  matrix.clear();
}

void setAllarm(){
  TMRpcm tmrpcm;
  tmrpcm.speakerPin = Speaker;
  if (!SD.begin(7)) {
    Serial.println("SD fail");
    return;
  }
  tmrpcm.setVolume(4);
  tmrpcm.play("Allarm.wav");
  if(digitalRead(ButtonAllarm)==HIGH ||
      digitalRead(ButtonClock)==HIGH ||
      digitalRead(ButtonHour)==HIGH ||
      digitalRead(ButtonMin)==HIGH ||
      digitalRead(ButtonTemp)==HIGH){

    tmrpcm.stopPlayback();
    return;
  }
}
