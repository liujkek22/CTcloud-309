#include<stdio.h>
int main()
{
	int x,y,z;
	int fun(int x,int y);//x表示基数，y表示指数 
	scanf("%d %d",&x,&y);
	fun(x,y);
	z=fun(x,y);
	printf("%d",z);
}
int fun(int x,int y)
{
	int a,b=1;
	for(a=1;a<=y;a++){
	 b=b*x;
	}
	return (b);
}
