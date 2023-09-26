#include<stdio.h>
int main()
{
    int a=0,b=0,c=0,d=0;//a表示英文字母,b表示空格,c表示数字,d表示其它字符 
    char e;
    printf("输入一串字符以确定它的组成成分:");
    while((e=getchar())!='\n')
    {
        if(e>='A'&&e<='Z')
        a++;
        else if(e>='a'&&e<='z')
        a++;
        else if(e==' ') 
        b++;
        else if(e>='0'&&e<='9')
        c++;
        else 
        d++;
    }
    printf("英文字母个数为:%d 空格个数为:%d 数字个数为:%d 其它字符个数为:%d",a,b,c,d);
    return 0;
}
