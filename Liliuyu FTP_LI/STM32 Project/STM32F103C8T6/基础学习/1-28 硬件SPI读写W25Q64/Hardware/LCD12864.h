#ifndef _LCD12864_H_
#define _LCD12864_H_

typedef struct
{
	uint8_t com;//显示地址
	uint8_t mun;//数据数量
	uint8_t *dat;//显示内容
}
LCD_InitTypeDef;

/*
当前定义为GPIOA低8位引脚为数据接口
GPIOB_0_1_10_11为控制引脚
*/

#define RS GPIO_Pin_0	//数据和指令使能，高为数据输入，低为指令输入
#define RW GPIO_Pin_1	//读写数据，若不读数据可之间接GND，高为读数据，低为写数据
#define EN GPIO_Pin_10	//数据使能,为高开始传输数据
#define PSB GPIO_Pin_11	//串并行使能，高为并行，低为串行

#define DATA_PROT GPIOA //数据引脚组
#define CMD_PROT GPIOB	//控制引脚组

#define RS_HIGH GPIO_SetBits(CMD_PROT,RS)//高
#define RS_LOW  GPIO_ResetBits(CMD_PROT,RS)//低

#define RW_HIGH GPIO_SetBits(CMD_PROT,RW)
#define RW_LOW  GPIO_ResetBits(CMD_PROT,RW)

#define EN_HIGH GPIO_SetBits(CMD_PROT,EN)
#define EN_LOW  GPIO_ResetBits(CMD_PROT,EN)

#define PSB_HIGH GPIO_SetBits(CMD_PROT,PSB)
#define PSB_LOW  GPIO_ResetBits(CMD_PROT,PSB)
//快捷控制宏定义，对应高低状态

#define CMD 0
#define DATA 1


void LCD12864_Write(uint8_t cmd,uint8_t data);
void LCD12864_Init(void);
void LCD_12864_Open(void);
void LCD_12864_Shut(void);
void LCD12864_Write_Word(LCD_InitTypeDef LCD_InitStructure);


#endif
