#include "temp.h"

int temperature(){
  int read_an=analogRead(tempSens);
  double temp_app=((read_an*0.0048)-0.5)*100;
  Serial.print("Read_an: ");
  Serial.println(read_an);
  Serial.print("Temp: ");
  Serial.println(temp_app);
  if (temp_app<temp-0.5 || temp_app>temp+0.5){
    double app=temp_app-(int)temp_app;
    if(app<0.3){
      temp=(int)temp_app;
    }
    else if (app>0.7){
      temp=(int)temp_app+1;
    }
    else {
      temp=(int)temp_app+0.5;
    }
  }
  return temp;
}

void showTemp(){
    print_temp((temperature());
    delay(5000);
}
