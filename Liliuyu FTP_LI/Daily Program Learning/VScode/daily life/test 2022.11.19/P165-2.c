#include<stdio.h>
int main()
{
    int n[10];
    int a,b,c;
    printf("输入10个数\n");
    for(a=0;a<=9;a++){
        scanf("%d",&n[a]);//输入10个数
    }
    for(a=0;a<=8;a++){//有10个数排序，则需要选择10-1，9趟
        for(b=a+1;b<=9;b++){//定位选择的元素
            if(n[a]>n[b]){
                c=n[a],n[a]=n[b],n[b]=c;//比较大小换位
            }
        }
    }
    for(a=0;a<=9;a++){
        printf("%d\t",n[a]);//输出排序后的数
    }
    return 0;
}

