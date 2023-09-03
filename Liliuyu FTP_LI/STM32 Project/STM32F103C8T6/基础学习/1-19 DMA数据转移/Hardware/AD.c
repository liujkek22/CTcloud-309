#include "stm32f10x.h"                  // Device header

void AD_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);//启用外部ADC1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//启用APIOA
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//ADCCLK=72MHz/6=12MHz
	
	GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_AIN;//AIN模拟输入模式
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 ;//启用0引脚
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOA,&GPIO_Iitstructure);
	
	
	ADC_InitTypeDef ADC_IintStructure;
	ADC_IintStructure.ADC_Mode = ADC_Mode_Independent;//ADC独立模式
	ADC_IintStructure.ADC_DataAlign = ADC_DataAlign_Right;//ADC数据右对齐
	ADC_IintStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//ADC外部触发源，不使用
	ADC_IintStructure.ADC_ContinuousConvMode = DISABLE;//是否连续转换
	ADC_IintStructure.ADC_ScanConvMode = DISABLE;//是否进行扫描,多通道扫描，单通道不扫描
	ADC_IintStructure.ADC_NbrOfChannel = 1;//通道数目
	ADC_Init(ADC1,&ADC_IintStructure);
	
	ADC_Cmd(ADC1,ENABLE);//启动ADC1
	ADC_ResetCalibration(ADC1);//开启复位校准
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);//等待复位校准完成,校准完成后数值为0，退出循环
	ADC_StartCalibration(ADC1);//开始校准
	while(ADC_GetCalibrationStatus(ADC1) == SET);//等待校准完成
	
}

uint16_t AD_GetValue(uint8_t ADC_Channel)
{
	ADC_RegularChannelConfig(ADC1, ADC_Channel, 1, ADC_SampleTime_55Cycles5);//设定规则组：使用ADC1，连接x通道，第一序列位置，55.5个ADCCLK的采样周期
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);//软件触发转换
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC) == RESET);//等待转换完成
	return ADC_GetConversionValue(ADC1);//获取转换值
}
