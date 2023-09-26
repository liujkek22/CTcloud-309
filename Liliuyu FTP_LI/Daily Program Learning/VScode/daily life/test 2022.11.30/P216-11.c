#include<stdio.h>
#include<string.h>
int main()
{
    void fun(char a[]);
    char a[10];
    printf("输入10个字符：");
    gets(a);
    fun(a);
    printf("从大到小排序为：");
    puts(a);
}
void fun (char a[])
{
    int x,y;
    char z;
    for(x=0;x<9;x++){
        for(y=0;y<9-x;y++){
            if(a[y]>a[y+1]){
                z=a[y];
                a[y]=a[y+1];
                a[y+1]=z;          
            }
        }
    }
}