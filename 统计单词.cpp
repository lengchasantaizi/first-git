//Í³¼Æµ¥´Ê 
#include <stdio.h>
#include <string.h>
#define N 10000000
int main(){
    char word[1100], sen[1000001];
    gets(word);
    gets(sen);
    strcat(word," ");
    strcat(sen," ");
    int i,j,k;
    int n,num,seat,flag;
    n=0;
    num=0;
    for(i=0;word[i]!='\0';i++){
        if(word[i]>='a')
            word[i]-=32;
    }
    for(i=0;sen[i]!='\0';i++){
        if (sen[i]>='a')
            sen[i]-=32;
    }
    for(i=0;sen[i]!='\0';i++){
        if(sen[i]==' '){
            flag=1;
            for(j=n,k=0;j<= i,word[k]!='\0';j++,k++){
                if(sen[j]==word[k]){
                    flag*=1;
                }
                else{
                    flag*=0;
                }
            }
            if(flag==1){
                num++;
            }
            if(num==1&&flag==1){
                seat=n;
            }
            n=i;
            n++;
        }
    }
    if (num==0){
        num = -1;
        printf("%d\n", num);
    }
    else if (num>=1){
        printf("%d %d\n",num,seat);
    }
}
