#include<stdio.h>
#include<string.h> 
void fun(char *a, char *b);
int main() {
    char a[80],b[80];
    printf("输入第一个字符串:\n");
    gets(a);
    printf("输入第二个字符串:\n");
    gets(b);
    fun(a,b);
    printf("拼接后的字符串为:\n"); 
    puts(a);
    return 0;
}

void fun(char *a, char *b)
{
    while(*a!=0) a++;
    while(*b!=0)
    {
        *a=*b;
        a++;
        b++;
    }
}
