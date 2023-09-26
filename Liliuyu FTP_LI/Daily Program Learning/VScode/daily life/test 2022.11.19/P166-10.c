#include<stdio.h>
#include<string.h>
int main()
{
    char n[3][80]={'\0'};
    int a=0,b=0,c=0,d=0,e=0,f,g;
    for(g=0;g<3;g++){
        for(f=0;f<80;f++){
            scanf("%c",&n[g][f]);
        }//输入字符串
    }
    for(g=0;g<3;g++){
    for(f=0;f<80;f++){
        if(n[g][f]>='A'&&n[g][f]<='Z')
        a++;
        else if(n[g][f]>='a'&&n[g][f]<='z')
        b++;
        else if(n[g][f]==' ') 
        c++;
        else if(n[g][f]>='0'&&n[g][f]<='9')
        d++;
        else 
        e++;
    }//判断字符类型并计数
    printf("第%d行 大写字母有%d个 小写字母有%d个 空格有%d个 数字有%d个 其它字符有%d个\n",g,a,b,c,d,e);
    a=0,b=0,c=0,d=0,e=0;//重置计数数
    }
    return 0;
}