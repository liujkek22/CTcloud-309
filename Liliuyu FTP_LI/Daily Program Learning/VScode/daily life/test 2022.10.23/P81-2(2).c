#include<stdio.h>
#include<math.h>
int main()
{
    float r=0.0021,t=0.0275,n=2,m=3,P;
    P=1000*(1+n*r);
    P=P*(1+m*t);
    printf("%.2f\n",P);
    return 0;
}