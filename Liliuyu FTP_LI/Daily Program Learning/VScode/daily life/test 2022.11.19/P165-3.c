#include<stdio.h>
int main()
{
    int n[3][3];
    int a,b,c,sum=0;
    for(a=0;a<=2;a++){
        for(b=0;b<=2;b++){
            printf("第%d行第%d列",a+1,b+1);//表示正在输入的数所对应的位置（去除0位）
            scanf("%d",&n[a][b]);
        }
    }//输入3X3的矩阵
    for(c=0;c<=2;c++){
        sum+=n[c][c];//计算对角线之和
    }
    printf("对角线之和为：%d",sum);
    return 0;
}