#include "stm32f10x.h"                  // Device header

uint16_t AD_Value[4];

void AD_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);//启用外部ADC1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//启用APIOA
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);//启用DMA1
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//ADCCLK=72MHz/6=12MHz
	
	GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_AIN;//AIN模拟输入模式
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 ;//启用0引脚
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOA,&GPIO_Iitstructure);
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);//设定规则组：使用ADC1，连接1通道，第一序列位置，55.5个ADCCLK的采样周期
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_55Cycles5);//设定规则组：使用ADC1，连接2通道，第二序列位置，55.5个ADCCLK的采样周期
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_55Cycles5);//设定规则组：使用ADC1，连接3通道，第三序列位置，55.5个ADCCLK的采样周期
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_55Cycles5);//设定规则组：使用ADC1，连接4通道，第四序列位置，55.5个ADCCLK的采样周期

	ADC_InitTypeDef ADC_IintStructure;
	ADC_IintStructure.ADC_Mode = ADC_Mode_Independent;//ADC独立模式
	ADC_IintStructure.ADC_DataAlign = ADC_DataAlign_Right;//ADC数据右对齐
	ADC_IintStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//ADC外部触发源，不使用
	ADC_IintStructure.ADC_ContinuousConvMode = ENABLE;//是否连续转换,是
	ADC_IintStructure.ADC_ScanConvMode = ENABLE;//是否进行扫描,多通道扫描，单通道不扫描
	ADC_IintStructure.ADC_NbrOfChannel = 4;//通道数目
	ADC_Init(ADC1,&ADC_IintStructure);
	
	DMA_InitTypeDef DMA_InitStructure;//配置DMA
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;//外设站点的起始地址，从自定义函数获取，ADC DR临时存储模块的地址
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//数据宽度,半字大小16位
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//是否自增，不自增，单一数据来源
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&AD_Value;//存储器站点的起始地址，从自定义函数获取
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//数据宽度，半字的大小
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//是否自增，自增，多存储地址
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;//传输方向,外设站点作为数据源SRC（source）源头
	DMA_InitStructure.DMA_BufferSize = 4;//传输数量，根据需要传输的数据个数定
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//是否自动重装,正常模式，进行自动重装
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;//选择是软件触发还是硬件触发，使用硬件触发
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;//优先级，中等优先级
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);//配置DMA1的通道1，应为ADC1的硬件触发通道只接到DMA1的通道1
	
	DMA_Cmd(DMA1_Channel1, ENABLE);//启用DMA1通道1
	
	ADC_DMACmd(ADC1,ENABLE);//开启ADC触发DMA的硬件信号
	
	ADC_Cmd(ADC1,ENABLE);//启动ADC1
	
	ADC_ResetCalibration(ADC1);//开启复位校准
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);//等待复位校准完成,校准完成后数值为0，退出循环
	ADC_StartCalibration(ADC1);//开始校准
	while(ADC_GetCalibrationStatus(ADC1) == SET);//等待校准完成
	
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);//软件触发转换

}
/*
void AD_GetValue(void)
{
	DMA_Cmd(DMA1_Channel1, DISABLE);//失能DMA1通道1
	DMA_SetCurrDataCounter(DMA1_Channel1,4);//重置转运计数器,转运4次
	DMA_Cmd(DMA1_Channel1, ENABLE);//启用DMA1通道1
	
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);//等待转运完成，检测转运完成的标志位
	DMA_ClearFlag(DMA1_FLAG_TC1);//清除标志位
	
}
*/
//获取ADC1转录值函数，若启用，则需关闭ADC连续转换和DMA的自动重装，并在主函数中调用进行转运数据
