#include<stdio.h>
int n=0;//n表示输入的个数
int m=0;//m表示要移动的位数
int main()
{
    void input(int *);
    void chuli(int *);
    void output(int *);
    int a[80];
    input(a);
    chuli(a);
    output(a);
    return 0;
}
void input(int *a)
{
    int x;
    printf("输入要进行处理的数字个数n:\n");
    scanf("%d",&n);//定义n的值
    printf("输入要进行移动的位数n:\n");
    scanf("%d",&m);
    printf("再输入n个数：\n");
    for(x=0;x<n;x++){
        scanf("%d",&a[x]);
    }
}
void chuli(int *a)
{
    int b[80];
    int *p1=a,x,y;
    p1=a+n-m;
    for(x=0;x<m;x++){
        b[x]=*p1;
        p1++;
    }
    p1=a;
    for(x=m;x<n;x++){
        b[x]=*p1;
        p1++;
    }
    for(x=0;x<n;x++){
        a[x]=b[x];
    }
}
void output(int *a)
{
    int x;
    printf("处理后为：\n");
    for(x=0;x<n;x++){
        printf("%d ",a[x]);
    }
}