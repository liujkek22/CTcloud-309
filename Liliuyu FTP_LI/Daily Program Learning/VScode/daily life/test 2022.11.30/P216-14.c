#include<stdio.h>
float a[10][5];//10名学生5门课的成绩
float b[10],c[5];//每个学生的平均分b,每门课的平均分c
int xs,kc;//学生，课程
float h,fc;//最高分,平均方差
int main()
{
    void aver_xs(void);//学生平均分
    void aver_km(void);//科目平均分
    void est(void);//最高分
    void aver_fc(void);//平均方差
    int i,j;
    for(i=0;i<10;i++){
        printf("输入第%d名学生的五门成绩：\n",i+1);
        for(j=0;j<5;j++){
            scanf("%f",&a[i][j]);
        }
    }//输入10名学生的成绩
    aver_xs( );
    aver_km( );
    est( );
    aver_fc( );
    for(i=0;i<10;i++){
        printf("第%d个学生的平均分：%8.2f\t",i+1,b[i]);
    }
    printf("\n");
    for(i=0;i<5;i++){
        printf("第%d门课的平均分：%8.2f\t",i+1,c[i]);
    }
    printf("最高分为%8.2f,是%d名学生的%d门课\n",h,xs+1,kc+1);
    printf("平均分方差为%8.2f",fc);
}
void aver_xs(void)
{
    int i,j;
    float s;
    for(i=0;i<10;i++){
        s=0;
        for(j=0;j<5;j++){
            s=s+a[i][j];
        }
        b[i]=s/5.0;
    }
}
void aver_km(void)
{
    int i,j;
    float s;
    for(i=0;i<5;i++){
        s=0;
        for(j=0;j<10;j++){
            s=s+a[j][i];
        }
        c[i]=s/10.0;
    }
}
void est(void)
{
    int i,j;
    h=a[0][0];
    for(i=0;i<10;i++){
        for(j=0;j<5;j++){
            if(a[i][j]>h){
                h=a[i][j];
                xs=i;
                kc=j;
            }
        }
    }
}
void aver_fc(void)
{
    int i,j;
    float sum=0;
    for(i=0;i<10;i++){
            sum=sum+b[i];
        }
    fc=(sum*sum/10.0)-((sum/10.0)*(sum/10.0));
}