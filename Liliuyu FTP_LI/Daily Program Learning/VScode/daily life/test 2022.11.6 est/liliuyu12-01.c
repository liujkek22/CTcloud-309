#include<stdio.h>
int main()
{
    int a,b,c,d;
    printf("输入三个数a,b,c将它们从大到小排序");
    scanf("%d,%d,%d",&a,&b,&c);
    if(a<b){
        d=a,a=b,b=d;
    }
    if(a<c){
        d=a,a=c,c=d;
    }
    if(b<c){
        d=b,b=c,c=d;
    }
    printf("从大到小排序为：%d>%d>%d",a,b,c);
    return 0;
}
