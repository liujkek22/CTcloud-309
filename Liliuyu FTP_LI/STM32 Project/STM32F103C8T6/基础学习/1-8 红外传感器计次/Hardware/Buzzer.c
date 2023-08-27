#include "stm32f10x.h"                  // Device header
void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_12;//启用12引脚
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOB,&GPIO_Iitstructure);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_12);//初始化引脚，默认为低电平，设置为高
}

void Buzzer_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);//设置为低电平
}

void Buzzer_OFF(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_12);//设置为高电平
}

void Buzzer_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_12)==0)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	} 
}
