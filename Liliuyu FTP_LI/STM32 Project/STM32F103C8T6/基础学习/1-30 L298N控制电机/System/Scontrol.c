#include "stm32f10x.h"                  // Device header
#include "NRF24L01.h"
#include "Key.h"
#include "sys.h"
#include "AD.h"
#include "MPU6050.h"
#include "OLED.h"
#include "Scontrol.h"
#include "Delay.h"
//该函数为发送端控制函数
uint8_t i,j;
uchar A[1],B[1],C[1],D[1],E[1],F[1],G[1];//指令集
int16_t AX,AY;//体感控制
uint8_t X1,Y1,X2,Y2;//遥控控制

void Send_Control_Init(void)//总体模块初始化
{
    NRF24L01_Init();
    Key_Init();
    AD_Init();
    MPU6050_Init();
    A[0]=0x01,B[0]=0x02,C[0]=0x03,D[0]=0x04,E[0]=0x05,F[0]=0x06,G[0]=0x07;//分别对应前进A、后退B、左转C、右转D、左平移E、右平移F、停止G
    while(NRF24L01_Check() == 1);//检测NRF24L01是否存在
}

void Send_Control_MOD(uint8_t MOD)
{
    if(MOD == 0)//按键模式
    {
        i = Key_GetNumA();
        OLED_ShowString(3,5,"Key-Press");
        if(i == 1)
        {
            SEND_BUF(A);
            OLED_ShowHexNum(2,6,A[0],2);
        }//前进
        if(i == 2)
        {
            SEND_BUF(B);
            OLED_ShowHexNum(2,6,B[0],2);
        }//后退
        if(i == 3)
        {
            SEND_BUF(C);
            OLED_ShowHexNum(2,6,C[0],2);
        }//左转
        if(i == 4)
        {
            SEND_BUF(D);
            OLED_ShowHexNum(2,6,D[0],2);
        }//右转
        if(i == 5)
        {
            SEND_BUF(E);
            OLED_ShowHexNum(2,6,E[0],2);
        }//左平移
        if(i == 6)
        {
            SEND_BUF(F);
            OLED_ShowHexNum(2,6,F[0],2);
        }//右平移
        if(i == 7)
        {
            SEND_BUF(G);
            OLED_ShowHexNum(2,6,G[0],2);
        }//停止        
    }
    else if(MOD == 1)//摇杆模式
    {
        X1 = AD_Value[0]/400;
        Y1 = AD_Value[1]/400;
        X2 = AD_Value[2]/400;
        Y2 = AD_Value[3]/400;
        OLED_ShowString(3,1,"X1:");
        OLED_ShowString(3,8,"Y1:");
        OLED_ShowString(4,1,"X2:");
        OLED_ShowString(4,8,"Y2:");
        OLED_ShowString(3,6," ");
        OLED_ShowNum(3,4,X1,2);
        OLED_ShowNum(3,11,Y1,2);
        OLED_ShowNum(4,4,X2,2);
        OLED_ShowNum(4,11,Y2,2);
        
        if(X1 >4 && X1 < 6 && Y1 < 6 && Y1 > 4 &&Y2 < 6 && Y2 > 4)
        {
            SEND_BUF(G);
            OLED_ShowHexNum(2,6,G[0],2);            
        }//停止
        if(X1 > 6)
        {
            SEND_BUF(A);
            OLED_ShowHexNum(2,6,A[0],2);
        }//前进
        if(X1 <4)
        {
            SEND_BUF(B);
            OLED_ShowHexNum(2,6,B[0],2);
        }//后退
        if(Y1 < 4)
        {
            SEND_BUF(C);
            OLED_ShowHexNum(2,6,C[0],2);            
        }//左转
        if(Y1 > 6)
        {
            SEND_BUF(D);
            OLED_ShowHexNum(2,6,D[0],2);
        }//右转
        if(Y2 > 6)
        {
            SEND_BUF(D);
            OLED_ShowHexNum(2,6,E[0],2);
        }//左平移
        if(Y2 > 6)
        {
            SEND_BUF(D);
            OLED_ShowHexNum(2,6,F[0],2);
        }//右平移
    }
    else if(MOD == 2)//体感控制模式
    {
        
    }
}
