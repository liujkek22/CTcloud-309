#include "stm32f10x.h"                  // Device header
#include "Servo.h"
#include "NRF24L01.h"
#include "OLED.h"
#include "key.h"
#include "final.h"
#include "Delay.h"
uint8_t m,ang=0;

void Final_Init(void)
{
    OLED_Init();
    Servo_Init();
    Key_Init();
    move_stop();
    OLED_ShowString(1,1,"Servo:");
    OLED_ShowString(2,1,"Servo:");
    OLED_ShowString(3,1,"Servo:");
    OLED_ShowString(4,1,"Servo:");
}

void crol(void)
{
    while(1)
    {
        m=Key_GetNum();
        if(m==1)
        {
            m=0;
            while(1)
            {
                move_gohead();
                if(Key_GetNum()==1){break;}
            }
        }
        if(m==2)
        {
            m=0;
            move_rest();
        }
    }
}

void move_stop(void)
{
    Servo1_SetAngle(90);
    Servo2_SetAngle(90);
    Servo3_SetAngle(90);
    Servo4_SetAngle(90);
    OLED_ShowNum(1,7,90,2);
    OLED_ShowNum(2,7,90,2);
    OLED_ShowNum(3,7,90,2);
    OLED_ShowNum(4,7,90,2);
    Delay_ms(600);
}

void move_rest(void)
{
    Servo1_SetAngle(40);  
    Servo2_SetAngle(140);
    Servo3_SetAngle(40);  
    Servo4_SetAngle(140);
    OLED_ShowNum(1,7,0,2);
    OLED_ShowNum(2,7,180,2);
    OLED_ShowNum(3,7,0,2);
    OLED_ShowNum(4,7,180,2);
    Delay_ms(600);
}

void move_gohead(void)
{
    Servo1_SetAngle(140);
    Servo2_SetAngle(90);
    Servo3_SetAngle(90);
    Servo4_SetAngle(90);
    OLED_ShowNum(1,7,140,2);
    OLED_ShowNum(2,7,90,2);
    OLED_ShowNum(3,7,90,2);
    OLED_ShowNum(4,7,90,2);
    Delay_ms(250);
    Servo1_SetAngle(90);
    Servo2_SetAngle(90);
    Servo3_SetAngle(40);
    Servo4_SetAngle(90);
    OLED_ShowNum(1,7,90,2);
    OLED_ShowNum(2,7,90,2);
    OLED_ShowNum(3,7,40,2);
    OLED_ShowNum(4,7,90,2);
    Delay_ms(250);
    Servo1_SetAngle(90);
    Servo2_SetAngle(90);
    Servo3_SetAngle(90);
    Servo4_SetAngle(40);
    OLED_ShowNum(1,7,90,2);
    OLED_ShowNum(2,7,90,2);
    OLED_ShowNum(3,7,90,2);
    OLED_ShowNum(4,7,40,2);
    Delay_ms(250);    
    Servo1_SetAngle(90);
    Servo2_SetAngle(140);
    Servo3_SetAngle(90);
    Servo4_SetAngle(90);
    OLED_ShowNum(1,7,90,2);
    OLED_ShowNum(2,7,140,2);
    OLED_ShowNum(3,7,90,2);
    OLED_ShowNum(4,7,90,2);
    Delay_ms(250);
}
