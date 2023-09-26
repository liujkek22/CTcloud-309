#include<stdio.h>
#include<string.h>
int main()
{
    void cpy(char *,char *,int );
    char a[80],b[80];
    int m;
    printf("输入一个字符串：\n");
    gets(a);
    printf("输入m,输出第m个以后的字符");
    scanf("%d",&m);
    if(strlen(a)<m){
        printf("超出字符串范围");
    }
    else{
        cpy(a,b,m);
    }
    printf("输出:\n");
    puts(b);
}
void cpy(char *p1,char *p2,int m)
{
    int x=0;
    for(x=0;x<m-1;x++){
        p1++;
    }
    while(*p1!='\0'){
        *p2=*p1;
        p1++;
        p2++;
    }
    *p2='\0';
}