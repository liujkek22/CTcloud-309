#include<stdio.h>
int main()
{
    int a[2][3]={{1,2,3},{4,5,6}};//表示a数组有2行3列，第一行为1，2，3，第二行为4，5，6.
    int b[3][2],i,j;
    printf("array a:\n");
    for(i=0;i<=1;i++){//处理数组a中第i行的数据
        for(j=0;j<=2;j++){//处理数组a中第j列的数据
            printf("%5d",a[i][j]);//输出a数组的数值
            b[j][i]=a[i][j];//将a数组元素的值赋给b数组
        }
        printf("\n");
    }
    printf("array b:\n");
    for(i=0;i<=2;i++){
        for(j=0;j<=1;j++){
            printf("%5d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}