#include<stdio.h>
int main()
{
    float h,r,l,s,sq,vq,vz;
    float pi=3.1415926;
    printf("请输入圆半径r,圆柱高h");
    scanf("%f,%f",&r,&h);//输入圆半径r和圆柱高h
    l=2*pi*r;//计算圆周长l
    s=r*r*pi;//计算圆面积s
    sq=4*pi*r*r;//计算圆球表面积sq
    vq=3.0/4.0*pi*r*r*r;//计算圆球的体积vq
    vz=pi*r*r*h;//计算圆柱体积vz
    printf("圆周长为:%.2f\n",l);
    printf("圆面积为:%.2f\n",s);
    printf("圆球的表面积为:%.2f\n",sq);
    printf("圆球体积为:%.2f\n",vq);
    printf("圆柱的体积为：%.2f\n",vz);
    return 0;
}