#include "stm32f10x.h"                  // Device header

#define CLK GPIO_Pin_5//时钟线
#define DI GPIO_Pin_7//主机输出线/从机输入线MOSI
#define DO GPIO_Pin_6//主机输入线/从机输出线MISO
#define CS GPIO_Pin_4//模块选择线
#define SPI_PROT GPIOA

void SPI_W_CS(uint8_t BitValue)//编辑CS/SS引脚
{
	GPIO_WriteBit(SPI_PROT,CS,(BitAction)BitValue);
}

void SPI_W_SCK(uint8_t BitValue)//编辑SCK引脚
{
	GPIO_WriteBit(SPI_PROT,CLK,(BitAction)BitValue);
}

void SPI_W_MOSI(uint8_t BitValue)//编辑DI引脚
{
	GPIO_WriteBit(SPI_PROT,DI,(BitAction)BitValue);
}

uint8_t SPI_R_MISO(void)//读取DO引脚
{
	return GPIO_ReadInputDataBit(SPI_PROT,DO);
}

void SPI_InitN(void)//初始化
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = CLK|DI|CS;
 	GPIO_Init(SPI_PROT, &GPIO_InitStructure);

 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = DO;
 	GPIO_Init(SPI_PROT, &GPIO_InitStructure);
	
	SPI_W_CS(1);
	SPI_W_SCK(0);//SPI模式0
}

void SPI_Start(void)
{
	SPI_W_CS(0);
}

void SPI_Stop(void)
{
	SPI_W_CS(1);
}

uint8_t SPI_SwapByte(uint8_t ByteSend)//交换/读写一个字节数据
{
	uint8_t ByteReceive = 0x00,i;
	
	for(i=0; i<8; i++)
	{
		SPI_W_MOSI(ByteSend & (0x80 >> i));
		SPI_W_SCK(1);
		if(SPI_R_MISO() == 1)
		{
			ByteReceive |= (0x80 >> i);
		}
		SPI_W_SCK(0);
	}
	return ByteReceive;
}
