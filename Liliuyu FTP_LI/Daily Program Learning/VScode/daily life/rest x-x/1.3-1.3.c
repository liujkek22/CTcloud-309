#include<stdio.h>
int max(int x,int y)       //定义max函数，函数值为整型，形参x y为整型
{
    int z;                  //定义本函数中用到的变量z为整型
    if(x>y)z=x;             //比较x,y的大小，如果x大于y，则执行z=x
    else z=y;               //否则执行z=y
    return(z);              //将z的值返回，通过max带回到调用函数的位置
}
int main()
{
    int a,b,c;              //定义变量
    scanf("%d,%d",&a,&b);   //从键盘输入变量a,b的值
    c=max(a,b);             //调用函数，将得到的值赋给c
    printf("max=%d\n",c);   //输出结果
    return 0;
}