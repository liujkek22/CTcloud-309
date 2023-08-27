#include"sys.h"

void delay_ms(uint x)
{
	uint i,j;
	for(i=x;i>0;i--)//执行x次循环
	{
		for(j=110;j>0;j--);//执行110次循环
	}
}

void delay_us(uint t)
{
    while(t--);     //t=0 ，退出
}
