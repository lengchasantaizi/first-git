#include <stdio.h>
int main(){
    int m,n,s=0,sum=0,i,j,flag,k;
    scanf("%d %d",&m,&n);
    int a[n],b[m];
    for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		}
    for(i=0;i<m;i++)
    b[i]=0;
    for(i=0;i<n;i++){   
    	flag=0;
        for(j=0;j<m;j++){
        	if(a[i]==b[j])
           flag=1;
        }
        	if(flag==0){
             sum=sum+1;
             b[s]=a[i];
             s=(s+1)%m;
            }
//			for(k=0;k<m;k++){
//             	printf("%d",b[k]);
//			 }
//			 printf("\n");
    }
    printf("%d\n",sum);
    return 0;
}
