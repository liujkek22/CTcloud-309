#include<stdio.h>
int main()
{
    int n[10][10];
    int a=0,b=0,c=0;
    for(a=0;a<=9;a++){
        n[a][a]=1;
        n[a][0]=1;
        }//给外框赋值
    for(a=2;a<=9;a++){
        for(b=1;b<=9;b++){
            if(b<a){
            n[a][b]=n[a-1][b-1]+n[a-1][b];
            }
        }
    }//计算内框
    for(a=0;a<=9;a++){
        for(b=0;b<=a;b++){
            printf("%d\t",n[a][b]);
        }
        printf("\n");
    }//输出数值   
    return 0; 
}