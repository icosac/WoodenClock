#include "temp.h"

void getTemp(){
  int read_an=analogRead(tempSens);
  double temp_app=((read_an*0.0048)-0.5)*100;
  Serial.print("Read_an: ");
  Serial.println(read_an);
  Serial.print("Temp: ");
  Serial.println(temp_app);
  if (temp_app<temperature-0.5 || temp_app>temperature+0.5){
    double app=temp_app-(int)temp_app;
    if(app<0.3){
      temperature=(int)temp_app;
    }
    else if (app>0.7){
      temperature=(int)temp_app+1;
    }
    else {
      temperature=(int)temp_app+0.5;
    }
  }
}

void showTemp(){
    print_temp(temperature);
    delay(5000);
}
