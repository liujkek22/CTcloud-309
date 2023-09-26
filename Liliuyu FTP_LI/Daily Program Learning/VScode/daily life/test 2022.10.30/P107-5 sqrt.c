#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    printf("输入一个小于1000的正数");
    scanf("%d",&a);
    if(a<0||a>=1000) {printf("不符合要求,请输入重新输入一个小于1000的正数");
    scanf("%d",&a); }
    b=sqrt(a);
    printf("输入的数的平方根的整数部分为：%d\n",b);
    return 0;
}