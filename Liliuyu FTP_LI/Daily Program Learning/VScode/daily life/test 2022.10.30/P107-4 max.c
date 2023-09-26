#include<stdio.h>
int main()
{
    int a,b,c,d;
    printf("输入三个数字a,b,c比较它们的大小");
    scanf("%d,%d,%d",&a,&b,&c);
    if(a>b) d=a;
    else d=b;
    if(d>c) d=d;
    else d=c;
    printf("最大值为：%d\n",d);
    return 0;
}