#include<stdio.h>
int main()
{
    float x,y,a,b,c;
    printf("输入两个数x,y");
    scanf("%f,%f",&x,&y);
    a=x+y;
    b=x-y;
    c=x*y;
    printf("x=%f,y=%f\n",x,y);
    printf("x+y=%.2f\nx-y=%.2f\nx*y=%.2f\n",a,b,c);
    return 0;
}