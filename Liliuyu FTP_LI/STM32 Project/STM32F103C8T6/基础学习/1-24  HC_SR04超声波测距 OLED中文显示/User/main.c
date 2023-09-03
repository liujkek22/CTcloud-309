#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "HC_SR04.h"

float Distance = 0;

int main(void)
{
	OLED_Init();
	HC_SR04_Init();
	OLED_ShowChineseString(1,2,0,5);
	
	while(1)
	{
		Distance = HC_SR04_avange();
		if(Distance>1000)//超出距离
		{
			OLED_ShowString(2,1,"                ");
			OLED_ShowChineseString(3,2,8,13);
			Delay_ms(1500);
		}
		else//在测量范围内
		{
			OLED_ShowNum(2,6,Distance,3);
			OLED_ShowString(3,1,"                ");
			OLED_ShowChineseString(2,5,6,7);
		}			
	}
}	
