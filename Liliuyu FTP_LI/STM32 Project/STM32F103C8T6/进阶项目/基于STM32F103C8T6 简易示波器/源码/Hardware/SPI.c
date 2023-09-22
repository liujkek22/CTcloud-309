#include "stm32f10x.h"                  // Device header
//�ò���ΪӲ��SPI���ò��֣�����SPI2���裬�ҽ���Ϊ����

#define DC GPIO_Pin_10
#define CS GPIO_Pin_9                   //SSģ��ѡ������
#define SPI_PROT GPIOA

void SPI_W_CS(uint8_t BitValue)         //�༭CS/SS����
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
	SPI_I2S_SendData(SPI2, TxData); //ͨ������SPIx����һ������
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET); //���ָ����SPI��־λ�������:���ܻ���ǿձ�־λ 						    					    
}

void SPI2_Init(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
    SPI_InitTypeDef  SPI_InitStructure;

	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );                         //PORTBʱ��ʹ�� 
	RCC_APB1PeriphClockCmd(	RCC_APB1Periph_SPI2,  ENABLE );                         //SPI2ʱ��ʹ�� 	
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 |GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                                 //PB13��PB15����������� 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);                                          //��ʼ��GPIOB
    GPIO_SetBits(GPIOB,GPIO_Pin_13|GPIO_Pin_15);                                    //PB13,PB15����������״̬Ϊ�ߵ�ƽ
    
	SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;                       //����ģʽѡ��,�������˫�������ģʽ:SPI����Ϊ���߷���
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		                            //����ģʽѡ����ģʽ
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;                               //����SPI�����ݴ�С:SPI����8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		                                //����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;	                                //����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		                                //NSSģʽѡ�����ģ��NSS
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;              //���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ2
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;                              //��������λ����λ����
	SPI_InitStructure.SPI_CRCPolynomial = 7;	                                    //CRCֵ����Ķ���ʽ
	SPI_Init(SPI2, &SPI_InitStructure);                                            
	SPI_Cmd(SPI2, ENABLE);                                                          //ʹ��SPI����
	SPI2_ReadWriteByte(0xff); 
} 

  
void SPI2_SetSpeed(u8 SPI_BaudRatePrescaler)                                        //���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ2
{
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));
	SPI2->CR1&=0XFFC7;
	SPI2->CR1|=SPI_BaudRatePrescaler;	                                            //����SPI2�ٶ� 
	SPI_Cmd(SPI2,ENABLE); 

} 
