#include<stdio.h>
#include<string.h>
void fun1(char a[],char b[],char c[]);
int main()
{
    char a[80],b[80],c[160];
    printf("输入两个字符串a、b进行连接\n");
    printf("字符串a:");
    gets(a);
    printf("字符串b:");
    gets(b);
    fun1(a,b,c);
    printf("输出\n");
    puts(c);
}
void fun1(char a[],char b[],char c[])
{
    int x,y;
    for(x=0;a[x]!=0;x++){
        c[x]=a[x];
    }
    for(y=0;b[y]!=0;y++){
        c[x+y]=b[y];
    }
    c[x+y]='\0';
}