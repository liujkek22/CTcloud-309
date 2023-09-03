#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"

int main(void)
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	
	OLED_ShowString(1,1,"Freq:00000Hz");
	
	PWM_SetPrescaler( 720 - 1 );  //Freq = 72M / (PSC + 1)/(ARR + 1)频率计算
	PWM_SetCompare1(50);		  //Duty = CCR / 100 占空比计算
	
	while(1)
	{
		OLED_ShowNum(1,6,IC_GetFreq(),5);
	}
}	
