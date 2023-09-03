#include "stm32f10x.h"                  // Device header

uint16_t MyDMA_Size;

void MyDMA_Init(uint32_t AddrA, uint32_t AddrB, uint16_t Size)//外设地址，目标地址，数据数量/传输次数
{
	MyDMA_Size = Size;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_InitTypeDef DMA_InitStructure;//配置DMA
	DMA_InitStructure.DMA_PeripheralBaseAddr = AddrA;//外设站点的起始地址，从自定义函数获取
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//数据宽度,字节的大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;//是否自增，自增
	DMA_InitStructure.DMA_MemoryBaseAddr = AddrB;//存储器站点的起始地址，从自定义函数获取
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;//数据宽度，字节的大小
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//是否自增，自增
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;//传输方向,外设站点作为数据源SRC（source）源头
	DMA_InitStructure.DMA_BufferSize = Size;//缓存区大小
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;//是否自动重装,正常模式，不进行重装
	DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;//选择是软件触发还是硬件触发，使用软件触发
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;//优先级，中等优先级
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);//配置DMA1的通道1
	
	DMA_Cmd(DMA1_Channel1, DISABLE);//启用DMA1通道1
}
void MyDMA_Transfer(void)
{
	DMA_Cmd(DMA1_Channel1, DISABLE);//失能DMA1通道1
	DMA_SetCurrDataCounter(DMA1_Channel1,MyDMA_Size);//重置转运计数器
	DMA_Cmd(DMA1_Channel1, ENABLE);//启用DMA1通道1
	
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);//等待转运完成，检测转运完成的标志位
	DMA_ClearFlag(DMA1_FLAG_TC1);//清除标志位
}
