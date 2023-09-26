#include<stdio.h>
int fun (int a[]);
int main()
{
	int a[80];
	int max,n,m;
	printf("输入一个数n:\n");
	scanf("%d",&n);
	printf("再输入n个数:");
	for(m=0;m<n;m++){
		scanf("%d",&a[m]);
	}
	a[n]='\0';
	max=fun(a);
	printf("其中的最大值为：%d",max);
}
int fun (int a[]) 
{
	int x,y=a[0];
	for(x=0;a[x]!=0;x++){
		if(a[x]>y){
			y=a[x];
		}
	}
	return (y);
}
