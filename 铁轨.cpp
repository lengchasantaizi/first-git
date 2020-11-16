//����
#include<stdio.h>
#include<stdlib.h> 
typedef struct node{
	struct node *last;
	int data;
	struct node *next;
}Node;
 
Node *head, *rear;
 
void in (int data) {	//��ջ 
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->last = rear;
	p->next = NULL;
	rear->next = p;
	rear = p;
}
 
void out () {	//��ջ 
	Node *p;
	p = rear;
	rear = rear->last;
	rear->next = NULL;
	free(p);
}
 
int main () {
	
	Node *p;
	
	int n = 5;	//��������Ϊ5�� 
//	char a[20] = {"12345"};
//	char a[20] = {"54321"};
	char a[20] = {"54123"};
	int k = 0;	//��¼Ŀǰѭ����a�±� 
	
	p = (Node*)malloc(sizeof(Node));
	p->data = -1;
	p->last = NULL;
	p->next = NULL;
	head = p;
	rear = p;
	
	int count = 1;
	while(k < n){	//��������˳�����yes 
		if(rear->data == -1){	//��ʱ��ջ 
			in(count ++);
		}
		
		if(rear->data == a[k++]-48){
			out();
		} else if(count > n){	//�������if�޷�����ʱͬʱ�Ѿ�û�п������ĳ������NO 
			printf("NO");
			exit(0);
		} else {	//�������if�޷������Ǽ������ 
			in(count ++);
		}
		
	}
	printf("YES");
	
	return 0;
}  
