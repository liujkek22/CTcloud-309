#include "stm32f10x.h"                  // Device header

void Encoder_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//开启时钟TIM3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//启用GPIOA，GPIO初始化
		
	GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_IPU;//复用上拉输入模式
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;//启用6、7
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOA,&GPIO_Iitstructure);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;//时钟分频模式为一分频（不分频）
	TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up;//时钟计数模式为向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period = 65536 - 1;//设置ARR的值，满量程计数
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1 - 1;//设置PSC的值，不进行分频
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0;//重复计数器，应TIM2为通用计数器，没有重复计数器则不启用
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);//时基单元配置
	
	TIM_ICInitTypeDef TIM_ICIintSturcture; //初始化输入捕获单元
	TIM_ICStructInit(&TIM_ICIintSturcture);
	TIM_ICIintSturcture.TIM_Channel = TIM_Channel_1;//选择通道一
	TIM_ICIintSturcture.TIM_ICFilter = 0xF;//滤波器最大计次模式
	TIM_ICInit(TIM3,&TIM_ICIintSturcture);//配置通道一
	TIM_ICIintSturcture.TIM_Channel = TIM_Channel_2;//选择通道二
	TIM_ICIintSturcture.TIM_ICFilter = 0xF;//滤波器最大计次模式
	TIM_ICInit(TIM3,&TIM_ICIintSturcture);//配置通道二
	
	TIM_EncoderInterfaceConfig( TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//配置编码器接口，TIM_ICPolarity_Rising极性不翻转,反转其一可以改变计数方向
	
	TIM_Cmd(TIM3,ENABLE);
}

int16_t Encoder_Get(void)
{
	int16_t Temp;
	Temp = TIM_GetCounter(TIM3);
	TIM_SetCounter(TIM3,0);
	return Temp;//记录并清除CNT
}
