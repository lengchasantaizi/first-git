//ø®∆¨”Œœ∑
#include<stdio.h>
#define N 100000
int main(){
	int ka[N],k[N];
	int n,front,rear,i,flag;
	while(~scanf("%d",&n)){
	 if(n==1){
        printf("Discarded cards:\n");
        printf("Remaining card: 1\n");
    }
    else{
	flag=0;
	for(i=0;i<n;i++)
		ka[i]=i+1;
		front=0;
		rear=n;
		while(front<rear){
			k[flag]=ka[front++];
			ka[rear++]=ka[front++];
			if(flag==0)
			printf("Discarded cards: %d, ",k[flag]);
			else if(flag>=n-2&&flag!=n-1)
			printf("%d",k[flag]);
			else if(flag==n-1)
			printf("\nRemaining card: %d",k[flag]);
			else
			printf("%d, ",k[flag]);
			flag++;
		}
	}
	printf("\n");
}
} 
//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//int a[50];
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        if(n==0)
//        {
//            continue;
//        }
//        if(n==1)
//        {
//            printf("Discarded cards:\n");
//            printf("Remaining card: 1\n");
//            continue;
//        }
//        queue<int>q;
//        for(int i=1;i<=n;i++)
//        {
//            q.push(i);
//        }
//        int sum1=0,sum2;
//        while(!q.empty())
//        {
//            a[sum1++]=q.front();
//            q.pop();
//            if(!q.empty())
//            {
//                int num=q.front();
//                q.pop();
//                if(!q.empty())
//                {
//                    q.push(num);
//                }
//                else
//                {
//                    sum2=num;
//                    break;
//                }
//            }
//        }
//        printf("Discarded cards: 1");
//        for(int i=1;i<sum1;i++)
//        {
//            printf(", %d",a[i]);
//        }
//        printf("\n");
//        printf("Remaining card: %d\n",sum2);
//    }
//    return 0;
//}

