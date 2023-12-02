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
	PWM_SetCompare1(Angle / 180 * 2000 + 500);
}

void Servo2_SetAngle(float Angle)
{
	PWM_SetCompare2(Angle / 180 * 2000 + 500);
}

void Servo3_SetAngle(float Angle)
{
	PWM_SetCompare3(Angle / 180 * 2000 + 500);
}

void Servo4_SetAngle(float Angle)
{
	PWM_SetCompare4(Angle / 180 * 2000 + 500);
}
