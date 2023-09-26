#include<stdio.h>
#include<string.h>
void fun(char a[],char b[]);
int main()
{
    char a[80],b[80];
    printf("输入一个字符串输出其中的元音字母：");
    gets(a);
    fun(a,b);
    printf("输出：");
    puts(b);
}
void fun(char a[],char b[])
{
    int x,y=0;
    for(x=0;a[x]!=0;x++){
        if(a[x]=='a'||a[x]=='e'||a[x]=='i'||a[x]=='o'||a[x]=='u'){
            b[y]=a[x];
            y++;
        }
    }
    b[y]='\0';
}