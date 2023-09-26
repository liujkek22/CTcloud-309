#include<stdio.h>
#include<string.h>
int main()
{
    void fun(char *p1,char *p2);
    char a[80],b[80],c[80];
    printf("输入三个字符串：\n");
    gets(a);gets(b);gets(c);
    if(strcmp(a,b)>0){
        fun(a,b);
    }
    if(strcmp(a,c)>0){
        fun(a,c);
    }
    if(strcmp(b,c)>0){
        fun(b,c);
    }
    printf("从小到大依次为：\n");
    puts(a);
    printf("\n");
    puts(b);
    printf("\n");
    puts(c);
    return 0;
}
void fun(char *p1,char *p2)
{
    char p[80];
    strcpy(p,p1);strcpy(p1,p2);strcpy(p2,p);
}