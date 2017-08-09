#include "temp.h"

void getTemp(){
  DHT dht(tempSens, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

  dht.begin();

  for (int i=0; i<100; i++){
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();
  }
  humidity=(int)(humidity/100);
  temperature=(int)(temperature/100);
}

void showTemp(){
    print_temp(temperature);
    delay(3000);
    print_hum(humidity);
    delay(2000);
}

// OLD CODE for TMP36
// void getTemp(){
//   int read_an=analogRead(tempSens);
//   double temp_app=((read_an*0.0048)-0.5)*100;
//   Serial.print("Read_an: ");
//   Serial.println(read_an);
//   Serial.print("Temp: ");
//   Serial.println(temp_app);
//   if (temp_app<temperature-0.5 || temp_app>temperature+0.5){
//     double app=temp_app-(int)temp_app;
//     if(app<0.3){
//       temperature=(int)temp_app;
//     }
//     else if (app>0.7){
//       temperature=(int)temp_app+1;
//     }
//     else {
//       temperature=(int)temp_app+0.5;
//     }
//   }
// }
