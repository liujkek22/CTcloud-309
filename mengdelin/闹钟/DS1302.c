#include <REG51.H>

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

//对寄存器进行定义，方便来运用
#define DS1302_SECOND		0x80
#define DS1302_MINUTE		0x82
#define DS1302_HOUR			0x84
#define DS1302_WP			0x8E		//‘WP’是‘写保护’的意思



char DS1302_Time[]={7,29,58,7,30,0};	//【时，分，秒,闹钟时，闹钟分，闹钟秒】

void DS1302_Init(void)
{
	DS1302_CE=0;
	DS1302_SCLK=0;
}


//“写”函数
void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);	//将Command的第零位取出
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);	//将Data的第零位取出
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}



//“读”函数
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i,Data=0x00;
	Command|=0x01;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);	//将Command的第零位取出
		DS1302_SCLK=0;
		DS1302_SCLK=1;
	}
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data|=(0x01<<i);}	
	}
	DS1302_CE=0;
	DS1302_IO=0;
	return Data;
}



/*
DS1302_WriteByte(0x8E,0x00);	//解除保护程序	
DS1302_WriteByte(0x80,0x55);	//对秒寄存器进行写入，因为是'写'所以命令字为0x80,后一个变量是设定'秒'的初始值，'分'不变
*/

//设置时间的函数
void DS1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP,0x00);	//关闭保护程序
	DS1302_WriteByte(DS1302_HOUR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_SECOND,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_WP,0x80);	//打开保护程序
}
	
/*
Second=DS1302_ReadByte(0x81);	//因为要对'秒'进行'读'操作，所以命令字返回0x81
Minute=DS1302_ReadByte(0x83);	//因为要对'分'进行'读'操作，所以命令字返回0x83
'Second/16*10+Second%16'将Second转为BCD码，即：用四位二进制数来表示一位十进制数；

*/

//读取时间的函数
void DS1302_ReadTime(void)
{
	unsigned char Temp;		//‘暂时’变量
	Temp=DS1302_ReadByte(DS1302_HOUR);		//因为等号右边的是pcd码所以还需要转成十进制
	DS1302_Time[0]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_MINUTE);		
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_SECOND);		
	DS1302_Time[2]=Temp/16*10+Temp%16;

}






