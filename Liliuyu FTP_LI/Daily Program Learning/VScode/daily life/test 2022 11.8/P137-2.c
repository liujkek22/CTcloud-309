#include<stdio.h>
#include<math.h>//程序中用到数学函数fabs，应包含头文件math.h
int main()
{
    int a=0;
	int sign=1;//sign用来表示数值的符号
	double pi=0.0,n=1.0,term=1.0;//pi开始表示多项式的值，最后代表Π的值，n代表分母，term表示当前项的值
	while(fabs(term)>=1e-8)//检查当前项term的绝对值是否大于或者等于10的-10次方，调节-x可以提高精确度x的值越大精确度越高
	{
		pi=pi+term;//把当前项累加到pi中
		n=n+2;//n+2是下一项的分母
		sign=-sign;//sign代表符号，下一项的符号与上一项的符号相反
		term=sign/n;//求出下一项的值term
		a++;
	}
	printf("循环了%d次\n",a);
	pi=pi*4;//多项式的和pi乘以4，才是Π的的近似值
	printf("pi=%10.8f\n",pi);//输出Π的值
	return 0;
}
