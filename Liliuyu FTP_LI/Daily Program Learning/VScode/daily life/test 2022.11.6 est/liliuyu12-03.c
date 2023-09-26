#include<stdio.h>
int main(){
	float sum=0,n=1;
	int a,b;
	for(a=1;a<=19;a++){
		n*=a;
		sum+=n;
	}
	printf("%.f\n",sum);
	return 0;
}

