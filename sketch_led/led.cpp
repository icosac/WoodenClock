#include "led.h"
#include "variables.h"

byte one[]= {B01000000,
             B11000000,
             B01000000,
             B01000000,
             B01000000,
             B01000000,
             B01000000,
             B01000000,
             B11100000
};

byte two[]= {B11100000,
             B00100000,
             B00100000,
             B00100000,
             B11100000,
             B10000000,
             B10000000,
             B10000000,
             B11100000
};

byte three[]= {B11100000,
               B00100000,
               B00100000,
               B00100000,
               B11100000,
               B00100000,
               B00100000,
               B00100000,
               B11100000
 };

byte four[]= {B10100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000
};

byte five[]= {B11100000,
              B10000000,
              B10000000,
              B10000000,
              B11100000,
              B00100000,
              B00100000,
              B00100000,
              B11100000
};

byte six[]=  {B11100000,
              B10000000,
              B10000000,
              B10000000,
              B11100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000
};

byte seven[]={B11100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000
};

byte eight[]={B11100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000
};

byte nine[]={ B11100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000
};

byte zero[]={ B11100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000
};

byte degree[]={ B11100000,
              B10100000,
              B11100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000
};

byte sepClock[]={ B11100000,
              B00000000,
              B01000000,
              B00000000,
              B00000000,
              B00000000,
              B01000000,
              B00000000,
              B00000000

};

byte sepAllarm[]={ B11100000,
              B00000000,
              B01000000,
              B00000000,
              B00000000,
              B00000000,
              B01000000,
              B00000000,
              B00000000

};

byte Celsius[]={ B0000000,
              B00000000,
              B11110000,
              B10000000,
              B10000000,
              B10000000,
              B10000000,
              B10000000,
              B11110000
};

byte percentage[]={ B1100100,
              B11010000,
              B00010000,
              B00100000,
              B00100000,
              B00100000,
              B01000000,
              B01011000,
              B10011000
};

byte *noArray[] = {zero, one, two, three, four, five, six, seven, eight, nine};

void print_time(int hh, int mm){
  String hour=convertIntTo2DigitString(hh);
  String min=convertIntTo2DigitString(mm);

  matrix.clear();
  matrix.drawBitmap(0, 0, (byte*)(noArray[(int)(hour[0]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(4, 0, (byte*)(noArray[(int)(hour[1]-'0')]), 3, 9, LEDBRIGHTNESS);
  if((previousSecond%2)==0){
    if (ALLARM){
      matrix.drawBitmap(8, 0, sepAllarm, 3, 9, LEDBRIGHTNESS);
    }
    else{
      matrix.drawBitmap(8, 0, sepClock, 3, 9, LEDBRIGHTNESS);
    }
  }
  matrix.drawBitmap(9, 0, (byte*)(noArray[(int)(min[0]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(13, 0, (byte*)(noArray[(int)(min[1]-'0')]), 3, 9, LEDBRIGHTNESS);
}

void print_temp(int tt){
  String temp=convertIntTo2DigitString(tt);

  matrix.clear();
  matrix.drawBitmap(0, 0, (byte*)(noArray[(int)(temp[0]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(4, 0, (byte*)(noArray[(int)(temp[1]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(8, 0, degree, 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(12, 0, Celsius, 4, 9, LEDBRIGHTNESS);
}


void print_hum(int uu){
  if (uu==100){//Fuck, are you in the Amazon rainforest??
    uu==99;
  }
  String hum=convertIntTo2DigitString(uu);

  matrix.clear();
  matrix.drawBitmap(0, 0, (byte*)(noArray[(int)(hum[0]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(5, 0, (byte*)(noArray[(int)(hum[1]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(10, 0, percentage, 3, 9, LEDBRIGHTNESS);
}
