#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_12|GPIO_Pin_13;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0)
	{
		Delay_ms(20);//消抖
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0);
		Delay_ms(20);//消抖
		KeyNum=1;//按键赋值为按键一
	}//左键
	return KeyNum;//返回按键值
}

//uint8_t Key_GetNumC(void)
//{
//    uint8_t KeyNumC = 0;
//    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0)
//	{
//		Delay_ms(20);
//		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0);
//		Delay_ms(20);
//		KeyNumC=7;
//	}//停止
//    return KeyNumC;//返回按键值
//}
