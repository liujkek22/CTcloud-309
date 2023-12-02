#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "IIC.h"
#include "TEA5767.h"

unsigned long g_frequency = TEA5767_MIN_KHZ;

static uint8_t s_radioWriteData[5] = {0x31,0xA0,0x20,0x11,0x00};          // 要写入TEA5767的数据，默认存台的PLL,104.3MHz
static uint8_t s_radioReadData[5] = {0};                                  // TEA5767读出的状态
static uint32_t s_pll = 0;

void TEA5767_Init(void)
{
    IIC_Init();
}

void TEA5767_Write(void)
{
    uint8_t i;
    
    IIC_Start();
    IIC_SendByte(TEA5767_ADDR_W);
    IIC_WaitAck();
    for(i=0;i<5;i++)
    {
        IIC_SendByte(s_radioWriteData[i]);
        IIC_Ack();
    }
    IIC_Stop();
}

void TEA5767_Read(void)
{
    uint8_t i;
    uint8_t tempLow;
    uint8_t tempHigh;
    s_pll = 0;
    
    IIC_Start();
    IIC_SendByte(TEA5767_ADDR_R);
    IIC_WaitAck();
    for(i=0;i<5;i++)
    {
        s_radioReadData[i]=IIC_ReceiveByte();
    }
    IIC_Stop();
    tempHigh = s_radioReadData[0];
    tempLow = s_radioReadData[1];
    tempHigh &= 0x3f;
    s_pll = tempHigh*256 + tempLow;
}

void TEA5767_GetPLL(void)//计算PLL
{
    uint8_t HLSI;
    HLSI = s_radioWriteData[2] & 0x10;                                  // HLSI位
    if(HLSI)
    {
        s_pll = (uint32_t)((float)((g_frequency+225)*4)/(float)32.768);   // 频率单位:k
    }
    else
    {
        s_pll = (uint32_t)((float)((g_frequency-225)*4)/(float)32.768);   // 频率单位:k
    }
}

uint32_t TEA5767_GetFrequency(void)//由PLL计算频率
{
    uint8_t HLSI;
    uint32_t pll = 0;
    pll = s_pll;
    HLSI = s_radioWriteData[2] & 0x10;
    if(HLSI)
    {
        g_frequency = (unsigned long)((float)(pll)*(float)8.192-225);   // 频率单位:KHz
    }
    else
    {
        g_frequency = (unsigned long)((float)(pll)*(float)8.192+225);   // 频率单位:KHz
    }
    
    return g_frequency;
}


void TEA5767_SetFrequency(uint32_t frequency)//设置频率
{
    g_frequency = frequency;
    TEA5767_GetPLL();
    s_radioWriteData[0] = s_pll / 256;
    s_radioWriteData[1] = s_pll % 256;
    s_radioWriteData[2] = 0x20;
    s_radioWriteData[3] = 0x11;
    s_radioWriteData[4] = 0x00;
    
    TEA5767_Write();
}

void TEA5767_Search(uint8_t mode)//手动收台 mode=1向上搜索/mode=0向下搜索
{
    TEA5767_Read();                                                     // 读取当前频率值 
    if(mode==1)                                                            // 向上搜索
    {
        g_frequency += 100;
        if(g_frequency > TEA5767_MAX_KHZ)                               // 频率达到最大值
        {
            g_frequency = TEA5767_MIN_KHZ;
        }
    }
    else if(mode==2)
    {
        g_frequency -= 100;
        if(g_frequency < TEA5767_MIN_KHZ)
        {
            g_frequency = TEA5767_MAX_KHZ;
        }
    }          
    TEA5767_GetPLL();                                                   // 计算PLL值
    s_radioWriteData[0] = s_pll / 256;
    s_radioWriteData[1] = s_pll % 256;
    s_radioWriteData[2] = 0x20;
    s_radioWriteData[3] = 0x11;
    s_radioWriteData[4] = 0x00;
    TEA5767_Write();
    TEA5767_Read();
    if(s_radioReadData[0] & 0x80)										// 搜台成功，RF=1，可保存其频率值待用
    {
        
    }    
}

void TEA5767_AutoSearch(uint8_t mode)
{
    uint8_t radioRf = 0;													// 1=发现一个电台，0=未找到电台
    uint8_t radioIf = 0;													// 中频计数结果
    uint8_t radioLev = 0;													// 信号电平ADC输出
	
    // 直到搜台成功，RF=1,0x31<IF<0x3E
    while((radioRf==0) || ((0x31>=radioIf)||(radioIf>=0x3E)))
    {
        if(mode)														// 频率增加搜台
        {
            s_radioWriteData[2] = 0xC0;									// SUD=1,SSLadc=7,HLSI=0
            g_frequency += 100;
            if(g_frequency > TEA5767_MAX_KHZ)							// 频率达到最大值
            {
                g_frequency = TEA5767_MIN_KHZ;
            }
        }
        else															// 频率减小搜台
        {
            s_radioWriteData[2] = 0x40;									// SUD=0,SSLadc=7,HLSI=0
            g_frequency -= 100;
            if(g_frequency < TEA5767_MIN_KHZ)
            {
                g_frequency = TEA5767_MAX_KHZ;
            }			
        }
        TEA5767_GetPLL();												// 转换为PLL值
        s_radioWriteData[0] = s_pll / 256 + 0xC0;						// MUTE=1,SM=1
        s_radioWriteData[1] = s_pll % 256;
        s_radioWriteData[3] = 0x11;
        s_radioWriteData[4] = 0x00;
        TEA5767_Write();												// 写入5个字节数据
        TEA5767_Read();													// 读取当前频率值 
        radioRf = s_radioReadData[0] & 0x80;
        radioIf = s_radioReadData[2] & 0x7F;
        radioLev = s_radioReadData[3] >> 4;
        radioLev = radioLev;
    }
    TEA5767_GetPLL();                                                   // 转换为PLL值
    s_radioWriteData[0] = s_pll / 256;									// MUTE=0,SM=0
    s_radioWriteData[1] = s_pll % 256;
    s_radioWriteData[3] = 0x11;
    s_radioWriteData[4] = 0x00;
    TEA5767_Write();                                                    // 写入5个字节数据
    TEA5767_Read();														// 读取当前频率值 
}

void TEA5767_Mute(uint8_t mode)//静音模式
{		
    if(mode == TEA5767_MUTE_ON)
    {
        s_radioWriteData[0] = s_radioWriteData[0] | 0x80;
    }
    else
    {
        s_radioWriteData[0] = s_radioWriteData[0] & 0x7F;
    }
    
    TEA5767_Write();
}
