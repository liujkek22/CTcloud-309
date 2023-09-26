#include<stdio.h>
int main()
{
    long I;
    double ztc,tc1,tc2,tc3,tc4,tc5;
    printf("请输入利润I");
    scanf("%d",&I);
    tc1=100000*0.1;
    tc2=tc1+100000*0.075;
    tc3=tc2+100000*0.05;
    tc4=tc3+200000*0.03;
    tc5=tc4+400000*0.015;
    if (I<100000) ztc=I*0.1;
    else if(I<=200000) ztc=tc1+(I-100000)*0.075;
    else if(I<=400000) ztc=tc2+(I-200000)*0.05;
    else if(I<=600000) ztc=tc3+(I-400000)*0.03;
    else if(I<=1000000) ztc=tc4+(I-600000)*0.015;
    else if(I>1000000) ztc=tc5+(I-100000)*0.01;
    printf("奖金为：%10.2f\n",ztc);
    return 0;
}