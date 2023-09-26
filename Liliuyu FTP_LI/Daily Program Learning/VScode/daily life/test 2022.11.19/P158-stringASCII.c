#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int i=0;
    printf("输入小于100字符的字符串,以求出它的ASCII值:");
    gets(a);
    printf("ASCII值为:\n");
    while(a[i]!='\0'){
        printf("%c=%d\t",a[i],a[i]);
        if((i+1)%5==0){
            printf("\n");
        }
        i++;
    }
    return 0;
}