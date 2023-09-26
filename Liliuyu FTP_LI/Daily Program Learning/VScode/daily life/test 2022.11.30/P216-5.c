#include<stdio.h>
#include<string.h>
void fun1(char a[]);
int main()
{
    char a[20];
    gets(a);
    fun1(a);
    puts(a);
}
void fun1(char a[])
{
    char b;
    int x,y;
    x=strlen(a);//计算字符个数
    for(y=0,x;y<x/2;y++,x--){
        b=a[y];
        a[y]=a[x-1];
        a[x-1]=b;
    }
}