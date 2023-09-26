#include<stdio.h>
int main()
{
    char c1,c2;
    printf("请连续输入两个字符 c1,c2:");
    c1=getchar();
    c2=getchar();
    printf("用putchar语句输出结果为:");
    putchar(c1);
    putchar(c2);
    printf("\n");
    printf("用printf语句输出为:");
    printf("%c%C\n",c1,c2);
    return 0;
}