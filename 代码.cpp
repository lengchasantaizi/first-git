#include<stdio.h>
#include<stdlib.h>
typedef struct word {
	char s[15]; //�����ʴ洢 
	struct word* next; //���� 
	int wordLen;
}Word;

int main(){
	FILE* fp;
	if(fp=fopen(file,"r")==NULL){
		printf("��ʧ��");
		exit(-1); 
	}
	else{
		printf("�򿪳ɹ�"); 
	}
	int i,j,z,cont;
	j=0;
	char str,n;	
//	char a[100]="I Love You,do you love me?"; //�洢���л� 
	Word* h1, * p1, * q1; //��ָ�� 
	//h1 = (Word*)malloc(sizeof(Word)); //���ռ� 
	p1 = essay; //ָ��ָ�򴫽�����ͷ��� 
	for(i=0;i<100;i++){ //��ѭ��һ����ĸһ����ĸѭ�� 
		fscanf(fp,"%c",&str);
		//str=a[i]; //����ĸ�洢
		if(str>='A'&&str<='Z')//�жϴ�Сд 
		str=str+32;
		if(cont=1&&str='\n')//����һ���Ƿ�б��ֱ������ѭ�� 
			continue; 
		else if(str='\n')//�����ڷ�б�ܼ�һ 
			cont=1; 
		else
			cont=0;//�����Ƿ�б������ 
		if(str!=' '){//�����ǿո� 
		q1 = (Word*)malloc(sizeof(Word));//���ռ���ַ� 
		q1->s[j]=str;
		printf("%c",q1->s[j]);
		j++;
		}
		else{//������ָ����� 
			j=0;
			p1->next=q1; //β��
			q1->next=NULL;
			p1=q1;
		}
		fclose(fp);
	}

} 
