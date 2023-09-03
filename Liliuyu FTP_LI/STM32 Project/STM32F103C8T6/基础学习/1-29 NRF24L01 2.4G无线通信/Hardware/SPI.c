#include "stm32f10x.h"                  // Device header

#define CLK GPIO_Pin_5//时钟线
#define DI GPIO_Pin_7//主机输出线/从机输入线MOSI
#define DO GPIO_Pin_6//主机输入线/从机输出线MISO
#define CS GPIO_Pin_4//模块选择线CS/SS
#define SPI_PROT GPIOA

//注释部分为软件SPI代码

void SPI_W_CS(uint8_t BitValue)//编辑CS/SS引脚
{
	GPIO_WriteBit(SPI_PROT,CS,(BitAction)BitValue);
}

//void SPI_W_SCK(uint8_t BitValue)//编辑SCK引脚
//{
//	GPIO_WriteBit(SPI_PROT,CLK,(BitAction)BitValue);
//}

//void SPI_W_MOSI(uint8_t BitValue)//编辑DI引脚
//{
//	GPIO_WriteBit(SPI_PROT,DI,(BitAction)BitValue);
//}

//uint8_t SPI_R_MISO(void)//读取DO引脚
//{
//	return GPIO_ReadInputDataBit(SPI_PROT,DO);
//}

void SPI_InitN(void)//初始化
{
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    
//	GPIO_InitTypeDef GPIO_InitStructure;
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Pin = CLK|DI|CS;
// 	GPIO_Init(SPI_PROT, &GPIO_InitStructure);
        
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Pin = DO;
// 	GPIO_Init(SPI_PROT, &GPIO_InitStructure);

    GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_4;//CS/SS
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//推挽输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5|GPIO_Pin_7;//CLK/DI
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//DO
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    SPI_InitTypeDef SPI_InitStructure;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;//主从模式选择，主模式
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;//传输模式选择，双线全双工模式    
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;//数据帧选择，8位数据帧
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;//数据先行位，高位先行
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;//波特率预分频器选择，128分频
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;//SPI模式选择
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;//NSS模式选择，软件模拟NSS
    SPI_InitStructure.SPI_CRCPolynomial = 7;//CRC校验多项式，默认值7
    SPI_Init(SPI1,&SPI_InitStructure);
    
    SPI_Cmd(SPI1,ENABLE);
    
    SPI_W_CS(1);
    
//	SPI_W_CS(1);
//	SPI_W_SCK(0);//SPI模式0
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
//	uint8_t ByteReceive = 0x00,i;
//	
//	for(i=0; i<8; i++)
//	{
//		SPI_W_MOSI(ByteSend & (0x80 >> i));
//		SPI_W_SCK(1);
//		if(SPI_R_MISO() == 1)
//		{
//			ByteReceive |= (0x80 >> i);
//		}
//		SPI_W_SCK(0);
//	}
//	return ByteReceive;
    
    while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE) != SET);//等待TXE
    
    SPI_I2S_SendData(SPI1,ByteSend);
    
    while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE) != SET);//等待RXNE
        
    return SPI_I2S_ReceiveData(SPI1);
}
