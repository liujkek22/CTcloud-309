#include"sys.h"

void delay_ms(uint x)
{
	uint i,j;
	for(i=x;i>0;i--)//ִ��x��ѭ��
	{
		for(j=110;j>0;j--);//ִ��110��ѭ��
	}
}

void delay_us(uint t)
{
    while(t--);     //t=0 ���˳�
}
