#include<stdio.h>
#include<string.h>
void fun (char a[],char b[],char c[]);
int main()
{
	char a[20];
	char b[20];
	char c[40];
	printf("输入第一个字符串:\n");
	gets(a);
	printf("输入第二个字符串:\n"); 
	gets(b);
	fun(a,b,c);
} 
void fun (char a[],char b[],char c[])
{
	printf("拼接的字符串为:\n%s",strcat(a,b)); 
}
