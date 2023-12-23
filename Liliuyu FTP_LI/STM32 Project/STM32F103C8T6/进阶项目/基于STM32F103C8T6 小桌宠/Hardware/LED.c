#include "stm32f10x.h"                  // Device header
#include "LED.h"

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = LED_1|LED_2|LED_3|LED_4;//对应LED1~4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
    LED_1_W(1);
    LED_2_W(1);
    LED_3_W(1);
    LED_4_W(1);   
}//初始化GPIOB


void LED_1_W(uint8_t BitValue)
{
    GPIO_WriteBit(LED_PORT,LED_1,(BitAction)BitValue);
}

void LED_2_W(uint8_t BitValue)
{
    GPIO_WriteBit(LED_PORT,LED_2,(BitAction)BitValue);
}

void LED_3_W(uint8_t BitValue)
{
    GPIO_WriteBit(LED_PORT,LED_3,(BitAction)BitValue);
}

void LED_4_W(uint8_t BitValue)
{
    GPIO_WriteBit(LED_PORT,LED_4,(BitAction)BitValue);
}

void LED_ALL_W(uint8_t BitValue)
{
    GPIO_WriteBit(LED_PORT,LED_1|LED_2|LED_3|LED_4,(BitAction)BitValue);
}
