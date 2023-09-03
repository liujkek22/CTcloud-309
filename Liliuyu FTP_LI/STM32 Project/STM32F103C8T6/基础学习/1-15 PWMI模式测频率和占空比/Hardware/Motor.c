#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//初始化方向控制引脚
	
	GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;//启用1、2引脚
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOA,&GPIO_Iitstructure);
	
	PWM_Init();
}

void Motor_SetSpeed(int8_t Speed)
{
	if(Speed >=0 )//正转
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);//Pin4为高电平
		GPIO_SetBits(GPIOA,GPIO_Pin_5);//Pin5为低电平
		PWM_SetCompare1(Speed);
	}
	if(Speed <0 )//反转
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4);//Pin4为低电平
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);//Pin5为高电平
		PWM_SetCompare1(-Speed);
	}
}
