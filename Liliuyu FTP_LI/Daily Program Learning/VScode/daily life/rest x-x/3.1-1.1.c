#include<stdio.h>
#define PI 3.14
int main()
{
    float r,s,v;
    r=2;
    s=4.0*PI*r*r;
    v=4.0/3.0*PI*r*r*r;
    printf("s=%f,v=%f\n",s,v);
    return 0;
}