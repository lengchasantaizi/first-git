//Ñ¯ÎÊÑ§ºÅ
#include<stdio.h>
#define N 1000000
int main(){
	int total,frequency,flag;
	int number[N],inquiry[N];
	int i,j,k;
	scanf("%d %d",&total,&frequency);
	for(i=1;i<=total;i++){
	scanf("%d",&number[i]);
	}
	for(j=1;j<=frequency;j++){
	scanf("%d",&flag);
	inquiry[j]=number[flag];
	}
	for(k=1;k<=frequency;k++){
	printf("%d\n",inquiry[k]);
	}
} 

