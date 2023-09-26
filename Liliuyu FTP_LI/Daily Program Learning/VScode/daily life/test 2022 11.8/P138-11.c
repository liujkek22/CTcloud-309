#include<stdio.h>
int main()
{
    float x=100,y;
    int a;
    for(a=0;a<10;a++){
        x=x/2;
    }
    y=100-x;
    printf("第%d次经过了%f米,反弹了%f米",a,y,x);
    return 0;
}