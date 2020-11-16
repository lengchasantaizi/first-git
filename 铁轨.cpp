//铁轨
#include<stdio.h>
#include<stdlib.h> 
typedef struct node{
	struct node *last;
	int data;
	struct node *next;
}Node;
 
Node *head, *rear;
 
void in (int data) {	//入栈 
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->last = rear;
	p->next = NULL;
	rear->next = p;
	rear = p;
}
 
void out () {	//出栈 
	Node *p;
	p = rear;
	rear = rear->last;
	rear->next = NULL;
	free(p);
}
 
int main () {
	
	Node *p;
	
	int n = 5;	//测试数据为5个 
//	char a[20] = {"12345"};
//	char a[20] = {"54321"};
	char a[20] = {"54123"};
	int k = 0;	//记录目前循环的a下标 
	
	p = (Node*)malloc(sizeof(Node));
	p->data = -1;
	p->last = NULL;
	p->next = NULL;
	head = p;
	rear = p;
	
	int count = 1;
	while(k < n){	//出轨完毕退出输入yes 
		if(rear->data == -1){	//空时入栈 
			in(count ++);
		}
		
		if(rear->data == a[k++]-48){
			out();
		} else if(count > n){	//在上面的if无法出轨时同时已经没有可以入轨的车就输出NO 
			printf("NO");
			exit(0);
		} else {	//在上面的if无法出轨是继续入轨 
			in(count ++);
		}
		
	}
	printf("YES");
	
	return 0;
}  
