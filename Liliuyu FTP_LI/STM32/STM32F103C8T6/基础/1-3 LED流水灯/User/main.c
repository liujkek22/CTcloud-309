#include "stm32f10x.h"                  // Device header
#include "delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//启用时钟
	GPIO_InitTypeDef GPIO_InitSturcture;
	GPIO_InitSturcture.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitSturcture.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitSturcture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitSturcture);
	//初始化
//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);//设置为低电平
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);//设置为高电平
//	GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);//Reset 置低电平
//	GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);//set置高电平
	while(1)
	{
		GPIO_Write(GPIOA,~0x0001);	//0000 0000 0000 0001
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0002);
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0004);
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0008);
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0010);
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0020);
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0040);
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0080);
		Delay_ms(500);
	}
}
