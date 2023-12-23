#include<stdio.h>
int main()
{ int a;
  scanf("%d",&a);
  if (a<0||a>100)
  { printf("请重输");}
  switch(a/10)
  { case 10:printf("等级为A\n");break;
  	case 9:printf("等级为A\n");break;
  	case 8:printf("等级为B\n");break;
  	case 7:printf("等级为C\n");break;
  	case 6:printf("等级为B\n");break;
  	case 5:printf("等级为A\n");break;
  	case 4:printf("等级为A\n");break;
  	case 3:printf("等级为A\n");break;
  	case 2:printf("等级为A\n");break;
  	case 1:printf("等级为A\n");break;
  }
  
}