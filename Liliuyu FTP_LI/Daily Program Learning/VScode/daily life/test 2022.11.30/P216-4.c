#include<stdio.h>
void fun1(int a[3][3],int x,int y);
int main()
{
    int a[3][3];
    int x,y;
    for(x=0;x<3;x++){
        for(y=0;y<3;y++){
            scanf("%d",&a[x][y]);
        }
    }
    fun1(a,x,y);
    return 0;
}
void fun1(int a[3][3],int x,int y)
{
    int m;
    for(x=0;x<3;x++){
        for(y=x;y<3;y++){
            m=a[x][y];
            a[x][y]=a[y][x];
            a[y][x]=m;
        }
    }
    for(x=0;x<3;x++){
        for(y=0;y<3;y++){
            printf("%d ",a[x][y]);
        }
        printf("\n");
    }
}