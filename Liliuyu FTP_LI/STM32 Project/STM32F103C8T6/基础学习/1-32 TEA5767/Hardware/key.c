#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
void Key_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_5;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0)
	{
		Delay_ms(20);//消抖
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0);
		Delay_ms(20);//消抖
		KeyNum=1;//按键赋值为按键一
	}
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0);
		Delay_ms(20);
		KeyNum=2;           
	}

	return KeyNum;//返回按键值
}


