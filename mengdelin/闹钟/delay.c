#include <REG51.H>
#include "intrins.h"

void delay(unsigned int x)	
{
	while(x)
	{
	unsigned char i, j;
	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	x--;
	}
	
}
