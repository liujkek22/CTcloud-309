#include<stdio.h>
int main()
{
    int n[5],m[5];
    int a,b,c;
    printf("输入5个数\n");
    for(a=0;a<=4;a++){
        printf("第%d个",a+1);
        scanf("%d",&n[a]);
    }
    for(a=0;a<=4;a++){
        m[a]=n[4-a];
    }
    printf("倒序为：");
    for(a=0;a<=4;a++){
        printf("%d",m[a]);
    }
    return 0;
}