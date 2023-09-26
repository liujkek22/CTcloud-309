#include<stdio.h>
int fun1(int x,int fl);
int main()
{
    int x,fl;
    printf("输入一个数判断是否是素数：");
    scanf("%d",&x);
    fl=fun1(x,fl);
    if(fl==1)
    printf("该数是素数");
    else if(fl==0)
    printf("该数不是素数");
    return 0;
}
int fun1(int x,int fl)
{
    int n,m;
    if(x<1)
    fl=0;
    else{
        for(n=2;n<x;n++){
            if(x%n==0){
                fl=0;break;
            }else fl=1;
        }
    }
    return fl;
}