#include<stdio.h>
int main()
{
    void input(int *);
    void paixv(int *);
    void output(int *);
    int a[10];
    input(a);
    paixv(a);
    output(a);
    return 0;
}
void input(int *a)//输入
{
    int x;
    printf("输入十个数：\n");
    for(x=0;x<10;x++){
        scanf("%d",&a[x]);
    }
}
void paixv(int *a)//处理
{
    int *max,*min,*p,temp;//定义指针和中间变量temp
    max=min=a;//使指针指向数组a的第一位
    for(p=a+1;p<a+10;p++){
        if(*p>*max){
            max=p;
        }
        else if(*p<*min){
            min=p;
        }
    }
    temp=a[0];a[0]=*min;*min=temp;//将最小数与第一个数交换
    if(max==a){//如果max=a则说明最大值为第一个数
        max=min;//让最大值指向当前最大值，也就是最小值的位置
    }
    temp=a[9];a[9]=*max;*max=temp;//将最大数与第一个数交换
}
void output(int *a)//输出
{
    int x;
    printf("处理后为：\n");
    for(x=0;x<10;x++){
        printf("%d",a[x]);
    }
}