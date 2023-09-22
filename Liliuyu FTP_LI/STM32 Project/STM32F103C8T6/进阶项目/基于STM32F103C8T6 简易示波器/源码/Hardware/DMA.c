#include "stm32f10x.h"                  // Device header

u32 MyDMA_Size;//����DMAÿ�����ݴ��͵ĳ���

void MYDMA_Config(DMA_Channel_TypeDef* DMA_CHx,u32 AddrA,u32 AddrB,u16 cndtr)    //(DMAͨ��CHx,�����ַ���洢��ַ�����ݴ�����)
{
 	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	                         //ʹ��DMAʱ��	
    DMA_DeInit(DMA_CHx);   														 //��DMA��ͨ��1�Ĵ�������Ϊȱʡֵ
	MyDMA_Size=cndtr;
    DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_PeripheralBaseAddr = AddrA;                            //DMA�������ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = AddrB;                                //DMA�ڴ����ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;                           //���ݴ��䷽�򣬴��ڴ��ȡ���͵�����
	DMA_InitStructure.DMA_BufferSize = cndtr;                                    //DMAͨ����DMA����Ĵ�С
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;             //�����ַ�Ĵ�������
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                      //�ڴ��ַ�Ĵ�������
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;      //���ݿ��Ϊ8λ
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;              //���ݿ��Ϊ8λ
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;                                //������   DMA_Mode_Circularѭ��ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;                        //DMAͨ�� xӵ�������ȼ� 
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;                                 //DMAͨ��xû������Ϊ�ڴ浽�ڴ洫��
	DMA_Init(DMA_CHx, &DMA_InitStructure);                                       //����DMA_InitStruct��ָ���Ĳ�����ʼ��DMA��ͨ��USART1_Tx_DMA_Channel����ʶ�ļĴ���

}


void DMA_Transfer(DMA_Channel_TypeDef*DMA_CHx)
{ 
	DMA_Cmd(DMA_CHx, DISABLE );                                                  //ʧ��DMA1ͨ��X      
 	DMA_SetCurrDataCounter(DMA_CHx,MyDMA_Size);                                  //����ת�˼�����
 	DMA_Cmd(DMA_CHx, ENABLE);                                                    //ʹ��DMA1ͨ��X  
}	
