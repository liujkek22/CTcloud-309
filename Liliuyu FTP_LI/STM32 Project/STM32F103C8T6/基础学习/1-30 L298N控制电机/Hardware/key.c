#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9 |GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_15;//
	GPIO_Init(GPIOA,&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
}

uint8_t Key_GetNumA(void)
{
	uint8_t KeyNumA = 0;
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==0)
	{
		Delay_ms(20);//消抖
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==0);
		Delay_ms(20);//消抖
		KeyNumA=1;//按键赋值为按键一
	}//前进
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_9)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_9)==0);
		Delay_ms(20);
		KeyNumA=2;
	}//后退
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)==0);
		Delay_ms(20);
		KeyNumA=3;
	}//左转
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)==0);
		Delay_ms(20);
		KeyNumA=4;
	}//右转
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)==0);
		Delay_ms(20);
		KeyNumA=5;
	}//左平移
    if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)==0);
		Delay_ms(20);
		KeyNumA=6;
	}//右平移 
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0);
		Delay_ms(20);
		KeyNumA=7;
	}//停止
	return KeyNumA;//返回按键值
}

uint8_t Key_GetNumB(void)
{
    uint8_t KeyNumB = 0;
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)==0);
		Delay_ms(20);
		KeyNumB=8;
	}//按键模式
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==0);
		Delay_ms(20);
		KeyNumB=9;
	}//摇杆模式
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0);
		Delay_ms(20);
		KeyNumB=10;
	}//体感模式
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==0);
		Delay_ms(20);
		KeyNumB=11;
	}//退出模式
    return KeyNumB;//返回按键值
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
