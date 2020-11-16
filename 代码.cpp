#include<stdio.h>
#include<stdlib.h>
typedef struct word {
	char s[15]; //按单词存储 
	struct word* next; //链表 
	int wordLen;
}Word;

int main(){
	FILE* fp;
	if(fp=fopen(file,"r")==NULL){
		printf("打开失败");
		exit(-1); 
	}
	else{
		printf("打开成功"); 
	}
	int i,j,z,cont;
	j=0;
	char str,n;	
//	char a[100]="I Love You,do you love me?"; //存储这行话 
	Word* h1, * p1, * q1; //开指针 
	//h1 = (Word*)malloc(sizeof(Word)); //开空间 
	p1 = essay; //指针指向传进来的头结点 
	for(i=0;i<100;i++){ //大循环一个字母一个字母循环 
		fscanf(fp,"%c",&str);
		//str=a[i]; //将字母存储
		if(str>='A'&&str<='Z')//判断大小写 
		str=str+32;
		if(cont=1&&str='\n')//若上一个是反斜杠直接跳过循环 
			continue; 
		else if(str='\n')//若存在反斜杠计一 
			cont=1; 
		else
			cont=0;//若不是反斜杠清零 
		if(str!=' '){//若不是空格 
		q1 = (Word*)malloc(sizeof(Word));//开空间存字符 
		q1->s[j]=str;
		printf("%c",q1->s[j]);
		j++;
		}
		else{//若不是指针后移 
			j=0;
			p1->next=q1; //尾插
			q1->next=NULL;
			p1=q1;
		}
		fclose(fp);
	}

} 
