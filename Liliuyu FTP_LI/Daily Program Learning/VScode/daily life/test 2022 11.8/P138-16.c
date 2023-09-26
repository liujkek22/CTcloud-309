#include<stdio.h>
int main()
{
    int x,y,z,a,b;//其中x表示列位，y表示空格的行位，z表示*的行位，a表示1~4行的当前行应该出现a个*，B表示5~7行的当前行应该出现b个*。
    for(x=1;x<=7;x++){
        if(x>=1&&x<=4){
            for(y=4-x;y>=0;y--){
                printf(" ");
            }
            a=2*x-1;
            for(z=1;z<=a;z++){
                printf("*");
            }printf("\n");
        }
        if(x>=5&&x<=7){
            for(y=x-4;y>=0;y--){
                printf(" ");
            }
            b=15-2*x;
            for(z=1;z<=b;z++){
                printf("*");
            }printf("\n");
        }
    }
    return 0;
}