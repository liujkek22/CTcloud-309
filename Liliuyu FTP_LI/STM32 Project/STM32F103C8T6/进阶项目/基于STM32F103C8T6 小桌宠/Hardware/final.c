#include "stm32f10x.h"                  // Device header
#include "Servo.h"
#include "NRF24L01.h"
#include "OLED.h"
#include "key.h"
#include "final.h"
#include "Delay.h"
#include "LED.h"

void Final_Init(void)
{
    OLED_Init();//OLED
    Servo_Init();//舵机
    LED_Init();//LED
    NRF24L01_Init();//2.4G无线通信模块
    move_chek();//运动检查
    LED_ALL_W(0);//灯全亮
}

void crol(void)
{
    uint8_t Buf[32] = {4, 20, 20, 20, 20};//其中一位数据长度，二位模式，其余四位控制数据
    /*
    调试标记 
    Buf[1]：左摇杆左40右0
    Buf[2]：左摇杆上40下0
    Buf[3]：右摇杆左0右40
    Buf[4]：右摇杆上40下0
    */
    while(1)//主函数进程
    {
        OLED_ShowMyPicture(3,32,32,48,0);
        OLED_ShowMyPicture(3,64,32,48,0);
//        OLED_Show_eyes_round();
        uint8_t flag=1;
        if (NRF24L01_Get_Value_Flag() == 0)
		{
			NRF24L01_GetRxBuf(Buf);
		}//数据获取
        if(Buf[1]>10&&Buf[2]>25&&Buf[4]>25)//摆动
        {
            move_shakebody();
            Buf[2] = 20;
            Buf[4] = 20;
        }
        if(Buf[1]>10&&Buf[2]<15&&Buf[4]<15)//挥手
        {
            move_shakehand();
            Buf[2] = 20;
            Buf[4] = 20;
        }
        if(Buf[1]<25)//板载LED控制
        {
            flag=flag%2;
            LED_ALL_W(flag);
            flag++;
        }
        if(Buf[2]>25)//前进
        {
            move_headpack(30);
        }
        if(Buf[2]<15)//后退
        {
            move_backpack(30);
        }
        if(Buf[3]<15)//左转
        {
            move_leftpack(30);
        }
        if(Buf[3]>25)//右转
        {
            move_rightpack(30);
        }
    }
}

void crol_L_H(float Angle)//左前
{
    Servo1_SetAngle(Angle);
}

void crol_L_L(float Angle)//左后
{
    Servo2_SetAngle(15+Angle);
}
void crol_R_H(float Angle)//右前
{
    Servo4_SetAngle(175-Angle);//误差值调整
}
void crol_R_L(float Angle)//右后
{
    Servo3_SetAngle(175-Angle);
}

void move_chek(void)
{
    move_rest();//准备步态
    move_restop();//从准备回复停止
}

void move_headpack(uint8_t Angle)//前进步态函数
{
    OLED_Show_eyes_crash();
    crol_L_H(90);
    crol_R_H(90-Angle);
    crol_L_L(90-Angle);
    crol_R_L(90);
        Delay_ms(Angle*3);
    crol_L_H(90+Angle);
    crol_R_H(90-Angle);
    crol_L_L(90-Angle);
    crol_R_L(90+Angle);
        Delay_ms(Angle*3);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(Angle*3);
    crol_L_H(90-Angle);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90-Angle);
        Delay_ms(Angle*3);
    crol_L_H(90-Angle);
    crol_R_H(90+Angle);
    crol_L_L(90+Angle);
    crol_R_L(90-Angle);
        Delay_ms(Angle*3);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(Angle*3);
    OLED_Clear();
}

void move_backpack(uint8_t Angle)//后退步态函数
{
    OLED_Show_eyes_crash();
    crol_L_H(90);
    crol_R_H(90+Angle);
    crol_L_L(90+Angle);
    crol_R_L(90);
        Delay_ms(Angle*3);
    crol_L_H(90-Angle);
    crol_R_H(90+Angle);
    crol_L_L(90+Angle);
    crol_R_L(90-Angle);
        Delay_ms(Angle*3);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(Angle*3);
    crol_L_H(90+Angle);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90+Angle);
        Delay_ms(Angle*3);
    crol_L_H(90+Angle);
    crol_R_H(90-Angle);
    crol_L_L(90-Angle);
    crol_R_L(90+Angle);
        Delay_ms(Angle*3);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(Angle*3);
    OLED_Clear();
}

void move_rightpack(uint8_t Angle)//右转步态函数
{
    OLED_Show_eyes_crash();
    crol_L_H(90);
    crol_R_H(90-Angle);
    crol_L_L(90+Angle);
    crol_R_L(90);
        Delay_ms(Angle*5);
    crol_L_H(90+Angle);
    crol_R_H(90-Angle);
    crol_L_L(90+Angle);
    crol_R_L(90-Angle);
        Delay_ms(Angle*5);
    crol_L_H(90+Angle);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90-Angle);
        Delay_ms(Angle*5);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(Angle*5);
    OLED_Clear();
}

void move_leftpack(uint8_t Angle)//左转步态函数
{
    OLED_Show_eyes_crash();
    crol_L_H(90);
    crol_R_H(90+Angle);
    crol_L_L(90-Angle);
    crol_R_L(90);
        Delay_ms(Angle*5);
    crol_L_H(90-Angle);
    crol_R_H(90+Angle);
    crol_L_L(90-Angle);
    crol_R_L(90+Angle);
        Delay_ms(Angle*5);
    crol_L_H(90-Angle);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90+Angle);
        Delay_ms(Angle*5);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(Angle*5);
    OLED_Clear();
}

void move_shakehand()//挥手函数
{
    uint8_t i;
    OLED_Show_eyes_confot();
    crol_L_H(90);  
    crol_R_H(90);
    crol_L_L(90);    
    crol_R_L(90);
    Delay_ms(540);
    crol_L_H(45);  
    crol_R_H(45);
    crol_L_L(45);    
    crol_R_L(45);
    Delay_ms(135);
    crol_L_H(100);  
    crol_R_H(100);
    crol_L_L(45);    
    crol_R_L(45);
    Delay_ms(135);
    for(i=0;i<4;i++)
    {
        crol_R_H(0);
        Delay_ms(400);
        crol_R_H(60);
        Delay_ms(400);
    }
    move_restop();
    OLED_Clear();
}

void move_shakebody(void)//摇摆函数
{
    OLED_Show_eyes_confot();
    crol_L_H(120);
    crol_R_H(120);
    crol_L_L(120);
    crol_R_L(120);
        Delay_ms(150);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(150);
    crol_L_H(60);
    crol_R_H(60);
    crol_L_L(60);
    crol_R_L(60);
        Delay_ms(150);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(150);
    OLED_Clear();
}
void move_restop(void)
{
    Delay_ms(540);
    crol_L_H(45);  
    crol_R_H(45);
    crol_L_L(35);    
    crol_R_L(35);
    Delay_ms(540);
    crol_L_H(25);  
    crol_R_H(25);
    Delay_ms(60);
    crol_L_H(90);
    crol_L_L(90);
    crol_R_H(90);
    crol_R_L(90);
    Delay_ms(195);
}//多次实验发现每移动1°大约要3ms

void move_stop(void)
{
    crol_L_H(90);
    crol_L_L(90);
    crol_R_H(90);
    crol_R_L(90);
    Delay_ms(195);
}

void move_rest(void)
{
    crol_L_H(90);  
    crol_R_H(90);
    crol_L_L(90);    
    crol_R_L(90);
    Delay_ms(540);
    crol_L_H(45);  
    crol_R_H(45);
    crol_L_L(45);    
    crol_R_L(45);
    Delay_ms(135);
    crol_L_H(100);  
    crol_R_H(100);
    crol_L_L(45);    
    crol_R_L(45);
    Delay_ms(135);    
}

void move_gohead(void)
{
    crol_L_H(90);
    crol_R_H(50);
    crol_L_L(50);
    crol_R_L(90);
        Delay_ms(120);
    crol_L_H(130);
    crol_R_H(50);
    crol_L_L(50);
    crol_R_L(130);
        Delay_ms(120);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(120);
    crol_L_H(50);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(50);
        Delay_ms(120);
    crol_L_H(50);
    crol_R_H(130);
    crol_L_L(130);
    crol_R_L(50);
        Delay_ms(120);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(120);    
}//调试函数，由该函数推写出move_headpack函数

void move_goback(void)
{
    crol_L_H(90);
    crol_R_H(130);
    crol_L_L(130);
    crol_R_L(90);
        Delay_ms(120);
    crol_L_H(50);
    crol_R_H(130);
    crol_L_L(130);
    crol_R_L(50);
        Delay_ms(120);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(120);
    crol_L_H(90);
    crol_R_H(50);
    crol_L_L(50);
    crol_R_L(90);
        Delay_ms(120);
    crol_L_H(130);
    crol_R_H(50);
    crol_L_L(50);
    crol_R_L(130);
        Delay_ms(120);
    crol_L_H(90);
    crol_R_H(90);
    crol_L_L(90);
    crol_R_L(90);
        Delay_ms(120); 
}//调试函数，由该函数推写出move_backpack函数

void move_right(void)
{
    crol_L_H(80);
    crol_R_H(50);
    crol_L_L(130);
    crol_R_L(80);
        Delay_ms(120);
    crol_L_H(130);
    crol_R_H(50);
    crol_L_L(130);
    crol_R_L(50);
        Delay_ms(120);
    crol_L_H(130);
    crol_R_H(80);
    crol_L_L(80);
    crol_R_L(50);
        Delay_ms(120);
    crol_L_H(80);
    crol_R_H(80);
    crol_L_L(80);
    crol_R_L(80);
        Delay_ms(120);
}

void OLED_Show_eyes_round(void)
{
    uint8_t i,j=20;
    OLED_Clear();
    for(i=1;i<64;i++)
    {   
    OLED_ShowMyPicture(3,i,32,48,0);
    OLED_ShowMyPicture(3,i+31,32,48,0);
    Delay_ms(j);
    }
    OLED_Clear();
    for(i=1;i<64;i++)
    {   
    OLED_ShowMyPicture(3,96-i,32,48,0);
    OLED_ShowMyPicture(3,65-i,32,48,0);
    Delay_ms(j);
    }
    OLED_Clear();      
}//表情呈现环视四周

void OLED_Show_eyes_crash(void)
{
    OLED_Clear();
    OLED_ShowPicture(1,1,128,64,0);
}//表情呈现 "> <"

void OLED_Show_eyes_confot(void)
{
    OLED_Clear();
    OLED_ShowPicture(1,1,128,64,1);
}//表情显示 “-▽- ”





