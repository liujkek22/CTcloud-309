#include<stdio.h>
int main()
{
    int m,n,i,a,b;
    printf("输入两个数字a,b以求出它们的最大公约数和最小公倍数:");
    scanf("%d,%d",&m,&n);
    if(m>n)
    m=m,n=n;
    else
    i=m,m=n,n=i;
    for(a=m;a>=1;a--)
        if((m%a==0)&&(n%a==0))
        {
         printf("最大公约数为%d\n",a);
         break;
        }
    b=m*n/a;//公式法求最小公倍数
    printf("最小公倍数为%d\n",b);
    return 0;
}