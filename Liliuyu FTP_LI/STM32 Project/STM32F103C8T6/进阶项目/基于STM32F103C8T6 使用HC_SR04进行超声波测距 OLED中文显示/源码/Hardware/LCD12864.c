#include "stm32f10x.h"                  // Device header
#include "LCD12864.h"
#include "delay.h"

void LCD12864_Write(uint8_t cmd,uint8_t data)//输入指令和数据 cmd 1 写数据 0 写指令
{
	if(cmd == 1)//判断当前是数据还是指令
	{
		RS_HIGH;
	}
	else RS_LOW;
	RW_LOW;
	EN_LOW;//数据准备
	GPIO_Write(DATA_PROT,data);
	Delay_ms(2);//保证数据完整
	EN_HIGH;//发送数据
	Delay_ms(2);//保证数据传输
	EN_LOW;
}

void LCD12864_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_Iitstructure.GPIO_Pin = 0x00FF ;//启用低8位引脚，0000 0000 1111 1111；
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_10MHz;//引脚速度10MHz
	GPIO_Init(DATA_PROT,&GPIO_Iitstructure);//配置GPIOA	
	
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_Iitstructure.GPIO_Pin = RS|RW|EN|PSB ;//启用
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_10MHz;//引脚速度10MHz
	GPIO_Init(CMD_PROT,&GPIO_Iitstructure);//配置GPIOB	
	//引脚初始化
	
	PSB_HIGH;
	LCD12864_Write(CMD,0x30);//基础配置 001<-1 00<-00(基本指令，8位数据接口)
	LCD12864_Write(CMD,0x06);//0000 1<-1<-00  AC自增 画面移动
	LCD12864_Write(CMD,0x0C);//开启显示和显示光标
	LCD12864_Write(CMD,0x01);//清屏
	LCD12864_Write(CMD,0x80);//确定起始位置为一行一列
	//初始化模块
}

void LCD_12864_Open(void)
{
	LCD12864_Write(CMD,0x0C);//开启显示和显示光标及闪烁
}

void LCD_12864_Shut(void)
{
	LCD12864_Write(CMD,0x08);//关闭显示和显示光标
}

void LCD12864_Write_Word(LCD_InitTypeDef LCD_InitStructure)
{
	LCD12864_Write( CMD, LCD_InitStructure.com);
	
	for(uint8_t i=0;i<LCD_InitStructure.mun;i++)
	{
		LCD12864_Write(DATA,*LCD_InitStructure.dat++);		
	}
}
