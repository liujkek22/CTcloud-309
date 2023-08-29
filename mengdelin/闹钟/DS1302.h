#ifndef _DC1302_H_
#define _DC1302_H_

extern char DS1302_Time[];

void DS1302_Init(void);
void DS1302_WriteByte(unsigned char Command,Data);//（命令字，数据）
unsigned char DS1302_ReadByte(unsigned char Command);//
void DS1302_SetTime(void);		//设置时间
void DS1302_ReadTime(void);		//读取时间


#endif
