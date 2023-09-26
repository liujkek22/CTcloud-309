#include<stdio.h>
int main()
{
	float x,y;
	printf("请输入顾客购买总金额：");
	scanf("%f",&x); 
	if(x<=200&&x>0){
		y=0.85*x;
	}
	else if(x>200&&x<=500){
		y=0.8*x-6;
	}
	else if(x>500){
		y=0.75*x-9;
	}
	else {
	printf("数据错误");
	}
	printf("顾客应付金额：%.2f",y);
	return 0;
}
