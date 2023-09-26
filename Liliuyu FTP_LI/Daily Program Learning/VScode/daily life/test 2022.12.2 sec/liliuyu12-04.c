#include<stdio.h>
#include<string.h>
int main()
{
	char str[5][10];
	char string[10];
	int i=0,j,k;
	for (i=0;i<5;i++)
	{
		printf("第%d个单词\n",i+1);
		gets(str[i]);
	}
	for(j=0;j<4;j++)
	{
		for(k=j+1;k<=4;k++)
		{
			if (strlen(str[j])>strlen(str[k])) 
			{
				strcpy(string,str[j]);
				strcpy(str[j],str[k]);
				strcpy(str[k],string);
			}
		}
	} 
	printf("从小到大排序为：\n");
	for(j=0;j<5;j++)
	{
		printf("%s\n",str[j]);
	}
	return 0;
}
