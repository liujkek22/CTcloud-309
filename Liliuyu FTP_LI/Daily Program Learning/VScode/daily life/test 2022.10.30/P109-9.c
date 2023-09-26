#include<stdio.h>
#include<math.h>
int main()
{
    int n,ws,gw,sw,bw,qw,ww;
    printf("输入一个不多于5位的正整数");
    scanf("%d",&n);
    while(n>99999) {printf("该数大于5位,请重新输入");
    scanf("%d",&n);}
    if(n>9999) ws=5;
    else if(n>999) ws=4;
    else if(n>99) ws=3;
    else if(n>9) ws=2;
    else ws=1;
    printf("该数是%d位数\n",ws);
    ww=(int)(n/10000);
    qw=(int)(n-ww*10000)/1000;
    bw=(int)(n-ww*10000-qw*1000)/100;
    sw=(int)(n-ww*10000-qw*1000-bw*100)/10;
    gw=(int)(n-ww*10000-qw*1000-bw*100-sw*10);
    printf("每一位数字为\n%d\n%d\n%d\n%d\n%d\n",ww,qw,bw,sw,gw);
    switch(ws)
    {
        case 5:printf("反序数字为：%d%d%d%d%d",gw,sw,bw,qw,ww);break;
        case 4:printf("反序数字为：%d%d%d%d",gw,sw,bw,qw);break;
        case 3:printf("反序数字为：%d%d%d",gw,sw,bw);break;
        case 2:printf("反序数字为：%d%d",gw,sw);break;
        case 1:printf("反序数字为：%d",gw);break;
    }
    return 0;
}