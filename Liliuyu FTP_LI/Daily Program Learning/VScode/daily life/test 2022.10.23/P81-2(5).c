#include<stdio.h>
#include<math.h>
int main()
{
    float r=0.0035,n=5,P;
    P=1000*pow(1+r/4,4*n);
    printf("%.2f\n",P);
    return 0;
}