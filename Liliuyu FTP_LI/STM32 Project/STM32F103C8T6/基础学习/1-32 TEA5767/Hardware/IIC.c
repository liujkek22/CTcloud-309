#include "stm32f10x.h"                  // Device header
#include "Delay.h"
//本函数部分为软件模拟IIC协议，需Delay函数支持
#define SCL_PROT GPIOB
#define IIC_SCL_PIN GPIO_Pin_0

#define SDA_PROT GPIOB
#define IIC_SDA_PIN GPIO_Pin_1

#define IIC_SDA_READ()      GPIO_ReadInputDataBit(IIC_SDA_PORT, IIC_SDA_PIN) 

//若更改该部分则需检查IIC_Init函数

void IIC_W_SCL(uint8_t BitValue)//1为拉高
{
	GPIO_WriteBit(SCL_PROT,IIC_SCL_PIN,(BitAction)BitValue);
	Delay_us(10);
}

void IIC_W_SDA(uint8_t BitValue)//1为拉高
{
	GPIO_WriteBit(SDA_PROT,IIC_SDA_PIN,(BitAction)BitValue);
	Delay_us(10);
}

uint8_t IIC_R_SDA(void)
{
	uint8_t BitValue;
	BitValue= GPIO_ReadInputDataBit(SDA_PROT, IIC_SDA_PIN);
	Delay_us(10);
	return BitValue;
}

void IIC_Init(void)//接口初始化
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_Iitstructure;
    GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_Out_OD;//开漏输出模式
	GPIO_Iitstructure.GPIO_Pin = IIC_SCL_PIN;
	GPIO_Init(SCL_PROT,&GPIO_Iitstructure);
    GPIO_Iitstructure.GPIO_Pin =IIC_SDA_PIN;
    GPIO_Init(SDA_PROT,&GPIO_Iitstructure);
	
	IIC_W_SCL(0);
    IIC_W_SDA(0);//初始化引脚
}

void IIC_Start(void)
{
	IIC_W_SDA(1);
	IIC_W_SCL(1);//释放引脚，SCL和SDA都为高时可能会发生误读，所以先释放SDA
	IIC_W_SDA(0);//拉低SDA
	IIC_W_SCL(0);//后拉低SCL
}

void IIC_Stop(void)
{
	IIC_W_SDA(0);//拉低SDA给出终止标志
	IIC_W_SCL(1);
	IIC_W_SDA(1);//释放引脚
}

void IIC_SendByte(uint8_t Byte)
{
	uint8_t i;
	for(i=0; i<8; i++ )
	{
		IIC_W_SDA(Byte & (0x80 >>i) );//将Byte的最高位映射在SDA上,>>右移
		IIC_W_SCL(1);
		IIC_W_SCL(0);//一位的数据传输完成
	}
}

uint8_t IIC_ReceiveByte(void)
{
	uint8_t i, Byte = 0x00;
	for(i=0; i<8; i++)
	{
		IIC_W_SDA(1);
		IIC_W_SCL(1);
		if(IIC_R_SDA() == 1)
		{
			Byte |= (0x80>>i);
		}
		IIC_W_SCL(0);
	}
	IIC_W_SCL(1);//释放SCL
	return Byte;
}

void IIC_SendAck(uint8_t AckBit)//写应答 写0则发出信号
{

	IIC_W_SDA(AckBit);
	IIC_W_SCL(1);
	IIC_W_SCL(0);//一位的数据传输完成
}

uint8_t IIC_ReceiveAck(void)//读应答 返回值为0则读到数据
{
	uint8_t  AckBit;
	IIC_W_SDA(1);
	IIC_W_SCL(1);
	AckBit = IIC_R_SDA();
	IIC_W_SCL(0);
	return AckBit;
}

uint8_t IIC_WaitAck(void)
{
    uint8_t result = 0;
    if(IIC_ReceiveAck())
    {
        result = 1;
    }
    else 
    {
        result = 0;
    }
    return result;
}

void IIC_Ack(void)
{
    IIC_SendAck(0);
}
void IIC_NO_Ack(void)
{  
    IIC_SendAck(1);
}
