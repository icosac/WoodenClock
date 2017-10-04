#include "led.h"

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
              B11100000
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
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000,
              B00000000
};

byte sepClock[]={ B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000
};

byte sepalarm[]={ B00000000,
              B00000000,
              B10000000,
              B00000000,
              B00000000,
              B00000000,
              B10000000,
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

byte percentage[]={
              B11001000,
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

void print_time(bool dots, short hh, short mm){
  String hour=int2String(hh);
  String min=int2String(mm);

  matrix.drawBitmap(0, 0, (byte*)(noArray[(int)(hour[0]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(4, 0, (byte*)(noArray[(int)(hour[1]-'0')]), 3, 9, LEDBRIGHTNESS);
  if(dots){
    if (ALARM){
      matrix.drawBitmap(8, 0, sepalarm, 3, 9, LEDBRIGHTNESS);
    }
    else{
      matrix.drawBitmap(8, 0, sepClock, 3, 9, LEDBRIGHTNESS);
    }
  }
  else {
    matrix.drawPixel(8, 2, 0);
    matrix.drawPixel(8, 6, 0);
    matrix.drawPixel(8, 3, 0);
    matrix.drawPixel(8, 7, 0);
  }
  matrix.drawBitmap(9, 0, (byte*)(noArray[(int)(min[0]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(13, 0, (byte*)(noArray[(int)(min[1]-'0')]), 3, 9, LEDBRIGHTNESS);
}

void print_temp(short tt){
  String temp=int2String(tt);

  matrix.drawBitmap(0, 0, (byte*)(noArray[(int)(temp[0]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(4, 0, (byte*)(noArray[(int)(temp[1]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(8, 0, (byte*)degree, 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(12, 0, (byte*)Celsius, 4, 9, LEDBRIGHTNESS);
}


void print_hum(short uu){
  if (uu==100){//Fuck, are you in the Amazon rainforest??
    uu=99;
  }
  String hum=int2String(uu);

  matrix.drawBitmap(0, 0, (byte*)(noArray[(int)(hum[0]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(5, 0, (byte*)(noArray[(int)(hum[1]-'0')]), 3, 9, LEDBRIGHTNESS);
  matrix.drawBitmap(10, 0, percentage, 5, 9, LEDBRIGHTNESS);
}

void flash (){
  for (short x=0;x<15;x++){
    for (short y=0;y<8;y++){
      matrix.drawPixel(x, y, 255);
    }
  }
  matrix.clear();
}

String int2String(short i)  {
  String s = String(i);
  if (i < 10)  {
    s = '0'+s;
  }
  return s;
}
