#include<stdio.h>
int main()
{
    int x,y,z=0;//z进行判断是否是质数，（默认是）0是1不是
    for(x=2;x<=100;x++){
        for(y=2;y<x;y++){
            if(x%y==0){//如果出现中途一个数可以整除
                z=1;//令z=1;
                break;//结束循环
            }
        }
        if(z==0){
            printf("%d ",x);
        }
        z=0;//重置z的值，进入下一循环
    }
    return 0;
}