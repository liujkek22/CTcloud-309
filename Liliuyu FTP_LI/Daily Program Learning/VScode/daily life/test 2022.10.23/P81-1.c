#include <stdio.h>
#include<math.h>
int main()
{
    float r=0.07,p,n=10;
    p=pow(1+r,n);
    printf("%.2f\n",p);
    return 0;
}