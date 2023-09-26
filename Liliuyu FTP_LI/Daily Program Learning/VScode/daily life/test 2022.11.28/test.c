#include<stdio.h>
#include<math.h>
void fun1(int f,int a,int b);
void fun2(int f,int a,int b);
void fun3( );
//声明函数
int main(void) {
	int a=0,b=0,c=0;
	int f;
	printf("please input three numbers:");
	scanf("%d %d %d", &a, &b, &c);
	f=b*b-4*a*c;

	if (f>0)
		fun1(f,a,b);
	else if (f==0)
		fun2(f,a,b);
	else if (f<0)
		fun3( );

      
	return 0;
}
//定义主函数
void fun1(int f,int a,int b) {
	double x1,x2,disc;
	disc=f;
	x1=(-b+sqrt(disc))/(2*a);
	x2=(-b-sqrt(disc))/(2*a);
	printf("x1=%.2f,x2=%.2f",x1,x2);
}

void fun2(int f, int a, int b) {
	double x1, disc;
	disc=f;
	x1=(-b+sqrt(disc))/2*a;
	printf("x1=x2=%.2f", x1);
}

void fun3()
{
	printf("not have result");
}