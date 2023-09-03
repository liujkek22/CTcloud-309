#include "stm32f10x.h"// Device header
#include <stdio.h>
#include <stdarg.h>

uint8_t Serial_RxData;
uint8_t Serial_RxFlag;

void Serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
    GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用输出模式
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_9 ;//启用9引脚
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOA,&GPIO_Iitstructure);//配置GPIOA	9
	
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_10 ;//启用10引脚
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOA,&GPIO_Iitstructure);//配置GPIOA	10

	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;//设置波特率
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//配置流控制器，不使用流控制
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;//TX数据输出模式及输入模式
	USART_InitStructure.USART_Parity = USART_Parity_No;//配置校验模式，无校验
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//配置停止位，1位停止位
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//配置字长，8位字长
	USART_Init(USART1,&USART_InitStructure);//配置USART1
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//开启RXNE的中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//配置中断的优先级
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//中断通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//所使用通道是否在列表中
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;//次优先级
	NVIC_Init(&NVIC_InitStructure);//配置中断参数
	
	
	USART_Cmd(USART1,ENABLE);//启用USART1
}

void Serial_SendByte(uint16_t Byte)//发送单字节
{
	USART_SendData(USART1,Byte);
	while (USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET );//检查传输数据寄存器空标志位，当数据传输完毕会置1
}

void Serial_SendArray(uint16_t *Array,uint16_t Length)//发送数组数据
{
	uint16_t i;
	for(i=0;i<Length;i++)
	{
		Serial_SendByte(Array[i]);
	}
}

void Serial_SendString(char *String)//发送字符串
{
	uint8_t i;
	for(i=0;String[i]!='\0';i++)
	{
		Serial_SendByte(String[i]);
	}
}

uint32_t Serial_Pow(uint32_t X,uint32_t Y)//次方函数，判断数字位数
{
	uint32_t Result = 1;
	while(Y --)
	{
		Result *= X;
	}
	return Result;
}

void Serial_SendNumber(uint32_t Number,uint8_t Lengeh)
{
	uint8_t i;
	for(i=0 ;i<Lengeh ;i++)
	{
		Serial_SendByte(Number/Serial_Pow(10,Lengeh-i-1)%10+'0');
	}
}

int fputc(int ch, FILE *f)
{
	Serial_SendByte(ch);
	return ch;
}

void Serial_Printf(char *format, ...)
{
	char String[100];
	va_list arg;
	va_start ( arg, format);
	vsprintf( String, format, arg);
	va_end(arg);
	Serial_SendString(String);
}

uint8_t Serial_GetRxFlag(void)//分装标志位函数
{
	if(Serial_RxFlag == 1)
	{
		Serial_RxFlag = 0;
		return 1;
	}
	return 0;
}

uint8_t Serial_GetRxData(void)//分装数据获取函数
{
	return Serial_RxData;
}

void USART1_IRQHandler(void)//中断转存数据
{
		if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==SET)
		{
			Serial_RxData=USART_ReceiveData(USART1);
			Serial_RxFlag = 1;
			USART_ClearITPendingBit(USART1,USART_FLAG_RXNE);//清除标志位
		}
}
