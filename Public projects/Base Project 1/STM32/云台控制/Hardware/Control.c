#include "stm32f10x.h"                  // Device header
#include "Control.h"

void Control_Init(void)
{
    float Angle1,Angle2;
    OLED_Init();
    Key_Init();
    AD_Init();
    PWM_Init();
    Angle1=90;
    Angle2=90;
    Servo_SetAngle1(Angle1);
    Servo_SetAngle2(Angle2);
    Delay_ms(1000);
    Angle1=0;
    Angle2=0;
    Servo_SetAngle1(Angle1);
    Servo_SetAngle2(Angle2);
    Delay_ms(700);
    Angle1=90;
    Angle2=90;
    Servo_SetAngle1(Angle1);
    Servo_SetAngle2(Angle2);
    Delay_ms(700);
    Angle1=0;
    Angle2=180;
    Servo_SetAngle1(Angle1);
    Servo_SetAngle2(Angle2);
    Delay_ms(700);
    Angle1=90;
    Angle2=90;
    Servo_SetAngle1(Angle1);
    Servo_SetAngle2(Angle2);
    Delay_ms(700);              
//    OLED_ShowPicture(1,1,128,64);
//    OLED_ShowChineseString(2,7,0,0);
//    Delay_ms(500);
//    OLED_ShowChineseString(3,7,1,1);
//    Delay_ms(500);
//    OLED_ShowChineseString(4,7,2,2);
//    Delay_ms(2500);
//    OLED_ShowChineseString(2,8,3,3);
//    OLED_ShowChineseString(3,8,4,4);
//    Delay_ms(1000);
	OLED_Clear();
    OLED_Base();//显示基础界面
}


uint8_t Yao_Gan_Control(void)
{
    uint8_t nun = 0;
    uint8_t X,Y;
    X=(AD_Value[2]/100)*4.5;
    Y=(AD_Value[3]/100)*4.5;
    OLED_ShowNum(2,5,X,4);//对应X轴
    OLED_ShowNum(2,13,Y,4);//对应Y轴
    
    Servo_SetAngle2(180-X);
    Servo_SetAngle1(180-Y);
    if(Key_GetNum() == 1)
        {
            nun=1;
            Servo_SetAngle1(90);
            Servo_SetAngle2(90);
        }
        return nun;
}//摇杆控制部分

uint8_t Ti_Gan_Control(void)
{
    uint8_t nun = 0;
//    int16_t AX,AY,GZ;
//    uint8_t Buf[32] = {4, 20, 20, 20, 20};;
//    MPU6050_GetData(&AX,&AY,&GZ);
//    OLED_ShowSignedNum(2,5,AX/200,2);
//    OLED_ShowSignedNum(2,13,AY/200,2);
//    OLED_ShowSignedNum(3,8,GZ/200,2);
//    Buf[2] = (AX/200+10)*2;//LY
//    Buf[1] = (AY/200+10)*2;//LX
//    Buf[3] = 40-(GZ/200+10)*2;//RY
//    NRF24L01_SendBuf(Buf);
    if(Key_GetNum() == 1)
        {
            nun=1;
        }
        return nun;
}//体感控制部分

void OLED_Base(void)
{
    OLED_Clear();
    OLED_ShowChineseString(1,3,5,8);//显示“模式选择”
    OLED_ShowChineseString(2,2,9,10);//显示“摇杆”
    OLED_ShowChineseString(2,4,5,6);//显示“模式”
    OLED_ShowChineseString(3,2,11,12);//显示“体感”
    OLED_ShowChineseString(3,4,5,6);//显示“模式”
}

void OLED_Base_Y(void)
{
    OLED_ShowChineseString(1,3,5,8);//显示“模式选择”
    OLED_ShowChineseString(2,2,9,10);//显示“摇杆”
    OLED_ShowChineseString(2,4,5,6);//显示“模式”
    OLED_ShowChineseString(3,2,11,12);//显示“体感”
    OLED_ShowChineseString(3,4,5,6);//显示“模式”
    OLED_ShowChineseString(3,6,14,14);
    OLED_ShowChineseString(2,6,13,13);//当前指向摇杆模式
}

void OLED_Base_T(void)
{
    OLED_ShowChineseString(1,3,5,8);//显示“模式选择”
    OLED_ShowChineseString(2,2,9,10);//显示“摇杆”
    OLED_ShowChineseString(2,4,5,6);//显示“模式”
    OLED_ShowChineseString(3,2,11,12);//显示“体感”
    OLED_ShowChineseString(3,4,5,6);//显示“模式”
    OLED_ShowChineseString(2,6,14,14);
    OLED_ShowChineseString(3,6,13,13);//当前指向摇杆模式
}

uint8_t Control(uint8_t mod,uint8_t come)
{
    if(mod == 0&&come == 0)
    {
        OLED_Base_Y();
    }
    if(mod == 1&&come == 0)
    {
        OLED_Base_T();
    }
    if(mod == 0&&come == 1)
    {
        OLED_Clear();
        OLED_ShowChineseString(1,3,9,10);//显示“摇杆”
        OLED_ShowChineseString(1,5,5,6);//显示“模式”
        OLED_ShowChineseString(2,1,15,15);
        OLED_ShowString(2,3,"X:");
        OLED_ShowString(2,11,"Y:");
        OLED_ShowChineseString(4,2,17,23);
        while(Yao_Gan_Control() == 0);
        OLED_Clear();
        return 4;
    }
    if(mod == 1&&come == 1)
    {
        OLED_Clear();
        OLED_ShowChineseString(1,3,11,12);//显示“体感”
        OLED_ShowChineseString(1,5,5,6);//显示“模式”
        OLED_ShowString(2,2,"AX:");
        OLED_ShowString(2,10,"AY:");
        OLED_ShowString(3,5,"GZ:");
        OLED_ShowChineseString(4,2,17,23);
        while(Ti_Gan_Control() == 0);
        OLED_Clear();
        return 4;
    }
    return 0;
}
