#include<stdio.h>
int main()
{
	int a,b,sum;
	for(a=1;a<=9;a++)
	{
	for(b=1;b<=9;b++)
	{
	sum=a*b;
	printf("%d*%d=%d\t",a,b,sum);
	}
	printf("\n");
	}
	return 0;
}
