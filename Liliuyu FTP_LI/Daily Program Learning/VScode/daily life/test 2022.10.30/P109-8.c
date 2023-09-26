#include<stdio.h>
int main()
{
    float x;
    char y;
    printf("输入学生的成绩");
    scanf("%f",&x);
    while (x>100||x<0){
        printf("请检查输入成绩，重新输入");
        scanf("%f",&x);
    }
    switch((int)(x/10))
    { 
        case 9:y='A';break;
        case 8:y='B';break;
        case 7:y='C';break;
        case 6:y='D';break;
        default:y='E';break;
    }
     printf("成绩等级是%c\n",y);  
     return 0;
}
