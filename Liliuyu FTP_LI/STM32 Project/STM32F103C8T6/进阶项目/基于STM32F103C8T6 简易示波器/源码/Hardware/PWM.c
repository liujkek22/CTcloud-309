#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//开启时钟TIM2
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//启用GPIOA，GPIO初始化
		
		GPIO_InitTypeDef GPIO_Iitstructure;
		GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出模式（允许定时器控制引脚，使用复用相关模式）
		GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_0;//启用0,1
		GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
		GPIO_Init(GPIOA,&GPIO_Iitstructure);
		
		
		TIM_InternalClockConfig(TIM2);//使用内部时钟
	
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
		TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;//时钟分频模式为一分频（不分频）
		TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up;//时钟计数模式为向上计数模式
		TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;//设置ARR的值
		TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;//设置PSC的值
		TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0;//重复计数器，应TIM2为通用计数器，没有重复计数器则不启用
		TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
		
		TIM_OCInitTypeDef TMO_OCInitstructure;
		TIM_OCStructInit(&TMO_OCInitstructure);//初始化输出比较器变量
		TMO_OCInitstructure.TIM_OCMode = TIM_OCMode_PWM1 ;//更改输出比较模式为PWM1
		TMO_OCInitstructure.TIM_OCPolarity = TIM_OCPolarity_High ;//OC极性为高极性，REF波形直接输出，当REF有效时输出高电平
		TMO_OCInitstructure.TIM_OutputState = TIM_OutputState_Enable ;//启用输出（输出使能）
		TMO_OCInitstructure.TIM_Pulse = 0;//设定CCR的值
		TIM_OC1Init(TIM2,&TMO_OCInitstructure);
        TIM_OC2Init(TIM2,&TMO_OCInitstructure);
        TIM_OC3Init(TIM2,&TMO_OCInitstructure);
        TIM_OC4Init(TIM2,&TMO_OCInitstructure);
       
	TIM_Cmd(TIM2, ENABLE);//启动TIM2定时器
}
}
void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2,Compare);//在运行过程中更改CCR的值
}

void Servo_SetAngle1(float Angle)
{
	PWM_SetCompare1(Angle / 180 * 2000 + 500);
}

void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM2,Compare);//在运行过程中更改CCR的值
}

void Servo_SetAngle2(float Angle)
{
	PWM_SetCompare2(Angle / 180 * 2000 + 500);
}

//void PWM_SetCompare3(uint16_t Compare)
//{
//	TIM_SetCompare3(TIM2,Compare);//在运行过程中更改CCR的值
//}

//void PWM_SetCompare4(uint16_t Compare)
//{
//	TIM_SetCompare4(TIM2,Compare);//在运行过程中更改CCR的值
//}

void PWM_SetPrescaler(uint16_t Prescaler)
{
	TIM_PrescalerConfig(TIM2,Prescaler,TIM_PSCReloadMode_Immediate);
}


/*
PWM频率 Freq=时钟频率/（PSC+1）/（ARR+1）
PWM占空比 Duty=CCR/(ARR+1)
PWM分辨率 Reso=1/(ARR+1)
*/
