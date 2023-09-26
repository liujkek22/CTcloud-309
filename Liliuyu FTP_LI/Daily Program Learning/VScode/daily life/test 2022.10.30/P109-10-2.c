#include<stdio.h>
int main()
{
    long I;
    double ztc,tc1,tc2,tc3,tc4,tc5;
    int x;
    printf("请输入利润I");
    scanf("%d",&I);
    tc1=100000*0.1;
    tc2=tc1+100000*0.075;
    tc3=tc2+100000*0.05;
    tc4=tc3+200000*0.03;
    tc5=tc4+400000*0.015;
    x=I/100000;
    switch((int)(x))
    {
    case 0:ztc=I*0.1;
    case 1:ztc=tc1+(I-100000)*0.075;break;
    case 2:
    case 3:ztc=tc2+(I-200000)*0.05;break;
    case 4:
    case 5:ztc=tc3+(I-400000)*0.03;break;
    case 6:
    case 7:
    case 8:
    case 9:ztc=tc4+(I-600000)*0.015;break;
    default:ztc=tc5+(I-100000)*0.01;break;
    }
    printf("奖金为：%10.2f\n",ztc);
    return 0;
}