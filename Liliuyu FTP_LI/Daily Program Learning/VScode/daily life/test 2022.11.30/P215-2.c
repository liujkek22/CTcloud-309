#include<stdio.h>
#include<math.h>
void fun1(int a,int b,int sq);
void fun2(int a,int b,int sq);
void fun3( );
int main()
{
    int a,b,c,sq;
    printf("输入三个数a b c:");
    scanf("%d %d %d",&a,&b,&c);
    sq=b*b-4*a*c;
    if(sq>0)
        fun1(a,b,sq);
    else if(sq==0)
        fun2(a,b,sq);
    else if(sq<0)
        fun3( );
    return 0;
}
void fun1(int a,int b,int sq)
{
    float x1,x2;
    x1=(-b+sqrt(sq))/(2*a);
    x2=(-b-sqrt(sq))/(2*a);
    printf("x1=%.2f x2=%.2f",x1,x2);
}
void fun2(int a,int b,int sq)
{
    float x;
    x=-b/(2*a);
    printf("x=%.2f",x);
}
void fun3( )
{
    printf("方程无解");
}