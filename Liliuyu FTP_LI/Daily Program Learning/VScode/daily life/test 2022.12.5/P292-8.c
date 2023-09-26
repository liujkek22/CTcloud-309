#include<stdio.h>
#include<string.h>
char n[80];
int main()
{
    void fun (char n[],int );
    int m;
    printf("输入一串字符以确定它的组成成分:");
    gets(n);
    m=strlen(n);
    fun(n,m);
    return 0;
}
void fun (char n[],int m)
{
    char *p;
    int a=0,b=0,c=0,d=0,e=0;//a表示大写字母，b表示小写字母,c表示空格,d表示数字,e表示其它字符
    for(p=&n[0];*p!='\0';p++)
    {
        if(*p>='A'&&*p<='Z')
        a++;
        else if(*p>='a'&&*p<='z')
        b++;
        else if(*p==' ') 
        c++;
        else if(*p>='0'&&*p<='9')
        d++;
        else 
        e++;
    }
    printf("大写字母个数为:%d 小写字母个数为：%d 空格个数为:%d 数字个数为:%d 其它字符个数为:%d",a,b,c,d,e); 
}