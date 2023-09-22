#include "stm32f10x.h"                  // Device header
//该部分为硬件SPI配置部分，采用SPI2外设，且仅作为主机

#define DC GPIO_Pin_10
#define CS GPIO_Pin_9                   //SS模块选择引脚
#define SPI_PROT GPIOA

void SPI_W_CS(uint8_t BitValue)         //编辑CS/SS引脚
{
	GPIO_WriteBit(SPI_PROT,CS,(BitAction)BitValue);
}

void SPI_Start(void)
{
	SPI_W_CS(0);
}

void SPI_Stop(void)
{
	SPI_W_CS(1);
}

void SPI2_ReadWriteByte(u8 TxData)
{			  
	SPI_I2S_SendData(SPI2, TxData); //通过外设SPIx发送一个数据
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET); //检查指定的SPI标志位设置与否:接受缓存非空标志位 						    					    
}

void SPI2_Init(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
    SPI_InitTypeDef  SPI_InitStructure;

	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );                         //PORTB时钟使能 
	RCC_APB1PeriphClockCmd(	RCC_APB1Periph_SPI2,  ENABLE );                         //SPI2时钟使能 	
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 |GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                                 //PB13，PB15复用推挽输出 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);                                          //初始化GPIOB
    GPIO_SetBits(GPIOB,GPIO_Pin_13|GPIO_Pin_15);                                    //PB13,PB15上拉，空闲状态为高电平
    
	SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;                       //传输模式选择,单向或者双向的数据模式:SPI设置为单线发送
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		                            //主从模式选择，主模式
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;                               //设置SPI的数据大小:SPI发送8位帧结构
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		                                //串行同步时钟的空闲状态为高电平
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;	                                //串行同步时钟的第二个跳变沿（上升或下降）数据被采样
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		                                //NSS模式选择，软件模拟NSS
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;              //定义波特率预分频的值:波特率预分频值为2
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;                              //数据先行位，高位先行
	SPI_InitStructure.SPI_CRCPolynomial = 7;	                                    //CRC值计算的多项式
	SPI_Init(SPI2, &SPI_InitStructure);                                            
	SPI_Cmd(SPI2, ENABLE);                                                          //使能SPI外设
	SPI2_ReadWriteByte(0xff); 
} 

  
void SPI2_SetSpeed(u8 SPI_BaudRatePrescaler)                                        //定义波特率预分频的值:波特率预分频值为2
{
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
	SPI2->CR1&=0XFFC7;
	SPI2->CR1|=SPI_BaudRatePrescaler;	                                            //设置SPI2速度 
	SPI_Cmd(SPI2,ENABLE); 

} 
