#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "Timer.h"

int16_t Num;//16位全局变量

int main(void)
{
	OLED_Init();
	Timer_Init();
	
	OLED_ShowString(1,1,"Num:");
	
	while(1)
	{
		OLED_ShowNum(1,5,Num,5);
		OLED_ShowNum(2,5,TIM_GetCounter (TIM2),5);//显示自动重装值
	}
}

void TIM2_IRQHandler(void)//TIM2中断函数
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)//获取TIM2的时钟更新标准位
	{
		Num++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);//清除TIM2的时钟更新标准位
	}
}	
