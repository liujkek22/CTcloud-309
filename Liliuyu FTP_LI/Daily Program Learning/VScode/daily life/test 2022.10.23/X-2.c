#include<stdio.h>
int main()
{
    int a,b,c,d,e;
    float n,m;
    printf("输入5个学生的计算机成绩a,b,c,d,e");
    scanf("%d,%d,%d,%d,%d",&a,&b,&c,&d,&e);
    n=a+b+c+d+e;
    m=n/5.0;
    printf("平均成绩为%.2f\n",m);
    return 0;
}