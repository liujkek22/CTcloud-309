#include<stdio.h>
int main()
{
    float add(float x,float y);
    float a,b,c;
    printf("please enter a and b:\n ");
    scanf("%f %f",&a,&b);
    c=add(a,b);
    printf("sum is %f\n",c);
}
float add(float x,float y)
{
    float z;
    z=x+y;
    return z;
}