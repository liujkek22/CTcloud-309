#include<stdio.h>
int main(){
	float sum=0,n=1;
	int a,b;
	for(a=1;a<=20;a++){
		n*=a;
		sum+=n;
	}
	printf("%.f\n",sum);
	return 0;
}