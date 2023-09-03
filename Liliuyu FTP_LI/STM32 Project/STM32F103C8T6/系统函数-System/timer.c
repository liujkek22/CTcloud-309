#include "stm32f10x.h"                  // Device header

//extern int16_t Num;//外部引用变量Num

void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//开启时钟TIM2
	
	TIM_InternalClockConfig(TIM2);//使用内部时钟
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;//时钟分频模式为一分频（不分频）
	TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up;//时钟计数模式为向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;//自动重装，计数10000次，减1是因为存在1的偏差
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;//预分频 对72Mz进行7200分频，减1是因为存在1的偏差，范围均在65535之间
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0;//重复计数器，应TIM2为通用计数器，没有重复计数器则不启用
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);//手动清除更新中断标志位，初始化后立刻进行中断，导致初始计数为1
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//开启中断，开启更新中断到NVIC的通路
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//NVIC优先级分组
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;//设置中断通道
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//使能中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;//相应优先级
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);//启动TIM2定时器
}

uint16_t Timer_GetCounter(void)
{
	return TIM_GetCounter(TIM2);
}

/*
void TIM2_IRQHandler(void)//TIM2中断函数
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)//获取TIM2的时钟更新标准位
	{
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);//清除TIM2的时钟更新标准位
	}
}	
*/
