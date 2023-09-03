#include "stm32f10x.h"                  // Device header

void IC_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//开启时钟TIM2
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//启用GPIOA，GPIO初始化
		
	GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_IPU;//复用上拉输入模式）
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_6;//启用6
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOA,&GPIO_Iitstructure);
	
	TIM_InternalClockConfig(TIM3);//使用内部时钟(初始化时基单元)
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;//时钟分频模式为一分频（不分频）
	TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up;//时钟计数模式为向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period = 65536 - 1;//设置ARR的值
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;//设置PSC的值
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0;//重复计数器，应TIM2为通用计数器，没有重复计数器则不启用
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	TIM_ICInitTypeDef TIM_ICIintSturcture; //初始化输入捕获单元
	TIM_ICIintSturcture.TIM_Channel = TIM_Channel_1;//选择通道一
	TIM_ICIintSturcture.TIM_ICFilter = 0xF;//滤波器最大计次模式
	TIM_ICIintSturcture.TIM_ICPolarity = TIM_ICPolarity_Rising;//上沿计次模式
	TIM_ICIintSturcture.TIM_ICPrescaler = TIM_ICPSC_DIV1;//不分频
	TIM_ICIintSturcture.TIM_ICSelection = TIM_ICSelection_DirectTI;//选择直连通道
	TIM_ICInit(TIM3,&TIM_ICIintSturcture);
	
	TIM_SelectInputTrigger(TIM3,TIM_TS_TI1FP1);//配置TRGI的触发源为TI1FP1
	
	TIM_SelectSlaveMode(TIM3,TIM_SlaveMode_Reset);//配置从模式为Reset,自动重装
	
	TIM_Cmd(TIM3,ENABLE);//启动TM3计时器
}
uint32_t IC_GetFreq(void)
{
	return 1000000 / (TIM_GetCapture1(TIM3)+1);
}
