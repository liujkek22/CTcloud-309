#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Servo.h"
void Servo_Init(void)
{
	PWM_Init();
}

//0->500  180->2500

void Servo1_SetAngle(float Angle)
{
    if(Angle>=0||Angle<=180)
    {
        TIM_SetCompare1(TIM2,50+(200*Angle/180));
    }
}

void Servo2_SetAngle(float Angle)
{
	if(Angle>=0||Angle<=180)
    {
        TIM_SetCompare2(TIM2,50+(200*Angle/180));
    }
}

void Servo3_SetAngle(float Angle)
{
	if(Angle>=0||Angle<=180)
    {
        TIM_SetCompare3(TIM2,50+(200*Angle/180));
    }
}

void Servo4_SetAngle(float Angle)
{
	if(Angle>=0||Angle<=180)
    {
        TIM_SetCompare4(TIM2,50+(200*Angle/180));
    }
}
