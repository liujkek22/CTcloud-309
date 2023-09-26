#include<stdio.h>
int main()
{
    void fun(int *p1,int *p2);
    int a,b,c;
    int *p1,*p2,*p3;
    printf("输入三个整数：\n");
    scanf("%d %d %d",&a,&b,&c);
    p1=&a;
    p2=&b;
    p3=&c;
    if(a>b){
        fun(p1,p2);
    }
    if(a>c){
        fun(p1,p3);
    }
    if(b>c){
        fun(p2,p3);
    }
    printf("从小到达排序为：%d<%d<%d",a,b,c);
    return 0;
}
void fun(int *p1,int *p2)
{
    int p;
    p=*p1;*p1=*p2;*p2=p;
}