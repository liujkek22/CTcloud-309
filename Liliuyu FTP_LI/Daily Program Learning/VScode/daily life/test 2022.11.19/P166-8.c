#include<stdio.h>
int main()
{
    int n[3][3],a,b,c,max,maxy,maxx,fl=0;
    for(a=0;a<=2;a++){
        for(b=0;b<=2;b++){
            scanf("%d",&n[a][b]);
            } 
    } 
    for(a=0;a<=2;a++){
        max=n[a][0];//假设最大值为改行的第一个数
        maxy=0;//记录假设数所在的列号
        for(b=0;b<=2;b++)
            if(n[a][b]>max){//比较该行的数大小
                max=n[a][b];
                maxy=b;//记录最大数的行号
        }
        fl=1;
        for(c=0;c<=2;c++)
            if(max>n[c][maxy]){//检验该点是不是该列的最小值
                fl=0;
                continue;
            }
        if(fl){
            printf("n[%d][%d]=%d\n",a,maxy,max);
            break;
        }
    }
    if(!fl)
    printf("没有鞍点\n");
    return 0;
}