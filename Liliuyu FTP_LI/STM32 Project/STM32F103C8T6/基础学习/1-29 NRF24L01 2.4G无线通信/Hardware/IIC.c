#include "stm32f10x.h"                  // Device header
#include "Delay.h"

#define SCL_PROT GPIOB
#define SCL GPIO_Pin_10
#define SDA_PROT GPIOB
#define SDA GPIO_Pin_11
//若更改该部分则需检查IIC_Init函数

void IIC_W_SCL(uint8_t BitValue)//1为拉高
{
	GPIO_WriteBit(SCL_PROT,SCL,(BitAction)BitValue);
	Delay_us(10);
}

void IIC_W_SDA(uint8_t BitValue)//1为拉高
{
	GPIO_WriteBit(SDA_PROT,SDA,(BitAction)BitValue);
	Delay_us(10);
}

uint8_t IIC_R_SDA(void)
{
	uint8_t BitValue;
	BitValue= GPIO_ReadInputDataBit(SDA_PROT, SDA);
	Delay_us(10);
	return BitValue;
}

void IIC_Init(void)//接口初始化
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_Out_OD;//开漏输出模式
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;//启用10、11引脚
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOB,&GPIO_Iitstructure);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_10 |  GPIO_Pin_11);//初始化引脚，默认为低电平，设置为高
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

void IIC_SendAck(uint8_t AckBit)//写应答
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
