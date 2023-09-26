#include<stdio.h>
#include<string.h>
void fun(char n[]);
int main()
{
    char n[80];
    gets(n);
    fun(n);
}
void fun(char n[])
{
    int a,b=0,c=0,d,e;
    for(a=0;n[a]!=0;a++){
        if(n[a]!=' '){//a为字符的现位置
        b++;//b表示字符长度
        if(b>c){
            c=b;//c表示记录的最长字符的长度
            d=a;//d为记录的最长字符的的位置
            }
            }
            if(n[a]==' '){
                b=0;//重置字符长度
                }
                }
                d=d+1;
                for(e=d-c;e<d;e++){//e表示最长字符的首位置
                printf("%c",n[e]);
                }
}