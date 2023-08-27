#include "stm32f10x.h"                  // Device header
#include "delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	//启用时钟
	GPIO_InitTypeDef GPIO_InitSturcture;
	GPIO_InitSturcture.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitSturcture.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitSturcture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitSturcture);
	//初始化
//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);//设置为低电平
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);//设置为高电平
//	GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);//Reset 置低电平
//	GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);//set置高电平
	while(1)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);//设置为低电平
		Delay_ms(100);
		GPIO_SetBits(GPIOB,GPIO_Pin_12);//设置为高电平
		Delay_ms(100);
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);//设置为低电平
		Delay_ms(100);
		GPIO_SetBits(GPIOB,GPIO_Pin_12);//设置为高电平
		Delay_ms(700);
	}
}
