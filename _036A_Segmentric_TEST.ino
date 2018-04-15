#include "TM1637.h"
#define CLK 2//pins definitions for TM1637 and can be changed to other ports       
#define DIO 3
TM1637 tm1637(CLK,DIO);
#define ON 1
#define OFF 0
unsigned char ClockPoint = 1;
void setup()
{
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}
void loop()
{
  for(int i=9; i>0; i=i-1){
  int8_t NumTab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};      //0~9,A,b,C,d,E,F
  int8_t ListDisp[0];
  tm1637.display(0,i); //hundreds
  tm1637.display(1,i); //tens
  tm1637.display(2,i); //ones
  tm1637.display(3,i); //ones but not hooked up
  tm1637.point(POINT_ON);
  delay(1200);
  }
}
