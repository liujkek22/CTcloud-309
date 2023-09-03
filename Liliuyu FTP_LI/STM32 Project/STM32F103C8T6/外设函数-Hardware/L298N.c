#include "stm32f10x.h"                  // Device header
#include "PWM.h"

#define CH1 GPIO_Pin_8
#define CH2 GPIO_Pin_9//右下
#define CH3 GPIO_Pin_10
#define CH4 GPIO_Pin_11//左下
#define L298N_PROTL GPIOA//前轮组
#define CH5 GPIO_Pin_12
#define CH6 GPIO_Pin_13//左上
#define CH7 GPIO_Pin_14
#define CH8 GPIO_Pin_15//右上
#define L298N_PROTR GPIOB//后轮组

#define CH1_LOW GPIO_ResetBits(L298N_PROTL,CH1)
#define CH1_HIGH GPIO_SetBits(L298N_PROTL,CH1)

#define CH2_LOW GPIO_ResetBits(L298N_PROTL,CH2)
#define CH2_HIGH GPIO_SetBits(L298N_PROTL,CH2)

#define CH3_LOW GPIO_ResetBits(L298N_PROTL,CH3)
#define CH3_HIGH GPIO_SetBits(L298N_PROTL,CH3)

#define CH4_LOW GPIO_ResetBits(L298N_PROTL,CH4)
#define CH4_HIGH GPIO_SetBits(L298N_PROTL,CH4)

#define CH5_LOW GPIO_ResetBits(L298N_PROTR,CH5)
#define CH5_HIGH GPIO_SetBits(L298N_PROTR,CH5)

#define CH6_LOW GPIO_ResetBits(L298N_PROTR,CH6)
#define CH6_HIGH GPIO_SetBits(L298N_PROTR,CH6)

#define CH7_LOW GPIO_ResetBits(L298N_PROTR,CH7)
#define CH7_HIGH GPIO_SetBits(L298N_PROTR,CH7)

#define CH8_LOW GPIO_ResetBits(L298N_PROTR,CH8)
#define CH8_HIGH GPIO_SetBits(L298N_PROTR,CH8)

void L298N_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = CH1|CH2|CH3|CH4;
 	GPIO_Init(L298N_PROTL, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = CH5|CH6|CH7|CH8;
 	GPIO_Init(L298N_PROTR, &GPIO_InitStructure);
    PWM_Init();
}

void L298N_Function(uint8_t dir)
{
    if(dir == 0)//正转
    {
       CH1_HIGH;
       CH2_LOW;//右下
       CH3_HIGH;
       CH4_LOW;//左下
       CH5_LOW;//左上
       CH6_HIGH;
       CH7_LOW;//右上
       CH8_HIGH;        
    }
    else if(dir == 1)//反转
    {
       CH1_LOW;
       CH2_HIGH;
       CH3_LOW;
       CH4_HIGH;
       CH5_HIGH;
       CH6_LOW;
       CH7_HIGH;
       CH8_LOW;   
    }
    else if(dir == 2)//左平移
    {
       CH1_HIGH;
       CH2_LOW;//右下
       CH3_LOW;
       CH4_HIGH;//左下
       CH5_LOW;//左上
       CH6_HIGH;
       CH7_HIGH;//右上
       CH8_LOW; 
    }
        else if(dir == 3)//右平移
    {
       CH1_LOW;
       CH2_HIGH;//右下
       CH3_HIGH;
       CH4_LOW;//左下
       CH5_HIGH;//左上
       CH6_LOW;
       CH7_LOW;//右上
       CH8_HIGH; 
    }
}
void L298N_Speed(uint8_t Speed)
{
    PWM_SetCompare1(Speed);
    PWM_SetCompare2(Speed); 
    PWM_SetCompare3(Speed); 
    PWM_SetCompare4(Speed);     
}

void L298N_STOP(void)
{
    CH1_HIGH;
    CH2_HIGH;
    CH3_HIGH;
    CH4_HIGH;
    CH5_HIGH;
    CH6_HIGH;
    CH7_HIGH;
    CH8_HIGH;    
    
}
