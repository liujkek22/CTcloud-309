#include<stdio.h>                   //文件包含命令
int main()                          //主函数
{
    int a,b,sum;                    //定义变量
    printf("input number:\n"); 
    scanf("%d,%d",&a,&b);           //给变量赋值
    sum=a+b;                        //求a和b的和
    printf("sum is %d\n",sum);      //输出结果
    return 0;
}