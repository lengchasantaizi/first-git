//Ô¼Éª·ò»· 
#include<stdio.h>
#include<stdlib.h> 
void JC(int N,int M){
    int a[N],data=0,number=0;
    int i,j; 
    for(j=0;j<N;j++){
         a[j]=(j+1);
    } 
   for(i=0;i<N;i++){
    if(a[i]>0){         
      data++; 
      if(data==M){
       printf("%d ",a[i]);
       a[i]=0;
       data=0;
       number++;
       if(number==N){
    	break;
        }       
      }        
    }
    if(i==(N-1)){
    	i=-1;
    	}
	}
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
    JC(N,M);
    }
