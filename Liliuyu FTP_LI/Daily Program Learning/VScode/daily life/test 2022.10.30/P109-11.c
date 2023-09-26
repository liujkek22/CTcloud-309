#include<stdio.h>
int main()
{
    int a,b,c,d,e;
    printf("请输入四个数a,b,c,d");
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    if(a>b) {e=a,a=b,b=e;}
    if(a>c) {e=a,a=c,c=e;}
    if(b>c) {e=b,b=c,c=e;}
    if(b>d) {e=b,b=d,d=e;}
    if(c>d) {e=c,c=d,d=e;}
    printf("排序结果如下：%d %d %d %d",a,b,c,d);
    return 0;
}