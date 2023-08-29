#include <REG51.H>
#include "delay.h"

sbit K1=P2^3;
sbit K2=P2^4;
sbit K3=P2^5;
sbit K4=P2^6;
/**
   *@brief	检测独立按键K1是否被按下
   *@param	无
   *@retval	按下按键的键码“1”
   */
unsigned char Key()
{
	unsigned char KeyNumber=0;
	
	if(K1==0){delay(20);while(K1==0);delay(20);KeyNumber=1;}
	if(K2==0){delay(20);while(K2==0);delay(20);KeyNumber=2;}
	if(K3==0){delay(20);while(K3==0);delay(20);KeyNumber=3;}
	if(K4==0){delay(20);while(K4==0);delay(20);KeyNumber=4;}
	
	return KeyNumber;
}
