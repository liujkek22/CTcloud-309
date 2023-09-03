#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "Motor.h"
#include "key.h"

int8_t KeyNum;//8位全局变量
int8_t Speed;
	
int main(void)
{
	OLED_Init();
	Motor_Init();
	Key_Init();
	
	OLED_ShowString(1,1,"Speed");
	
	Motor_SetSpeed(0);
	
	while(1)
	{
		KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
			Speed+=20;
			if(Speed>100)
			{
				Speed=0;
			}
		}
		Motor_SetSpeed(Speed);
		OLED_ShowSignedNum(1,7,Speed,3);
	}
	
}	
