#include <stdio.h>
void fun(int c[], int a[], int b[]);
int main()
 {
 int a[10]={0}; //a表示奇数数组
 int b[10]={0}; //b表示偶数数组
 int c[10];
 int n;
 printf("输入10个数字:");
 for (n = 0; n < 10; n++)
  scanf("%d", &c[n]);
 fun(c,a,b);
 printf("奇数有:") ;
 for (n=0;a[n]!= 0;n++)
  printf("%d ", a[n]);
 printf("\n偶数有:");
 for (n = 0; b[n] != 0; n++)
  printf("%d ", b[n]);
 return 0;
}
void fun(int c[], int a[], int b[]) 
{
 int x=0,y=0,z = 0;
 for (x=0;x<10;x++)
  {
    if (c[x]%2== 0)
     {
       b[y++] = c[x];
     }
    else 
     {
       a[z++] = c[x];
     }
   }
}
