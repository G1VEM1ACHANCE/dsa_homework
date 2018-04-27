#include<stack>
#include<queue>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int times;
	int operation,number;
	int sdetermine=1,qdetermine=1;
	scanf("%d",&times);
	stack<int>s;
	queue<int>q;
 	for(int i=0;i<times;i++)
	{
		scanf("%d%d",&operation,&number);
		if(operation==1){
			s.push(number);
			q.push(number);
		}
		if(operation==2){
			int p=s.top();
			cout<<s.top()<<" "<<number<<"\n";	
			if(s.top()==number&&sdetermine!=-1)
				sdetermine=1;
			else if(p!=number)
				sdetermine=-1;
			s.pop();
			if(q.front()==number&&qdetermine!=-1)
				qdetermine=1;
			else if(q.front()!=number)
				qdetermine=-1;
			q.pop();
			printf("\n%d %d\n",sdetermine,qdetermine);
		}
	}
	if(sdetermine==1&&qdetermine==1)
		printf("both");
	else if(sdetermine==1&&qdetermine==-1)
		printf("stack");
	else if(sdetermine==-1&&qdetermine==1)
		printf("queue");
	else 
		printf("neither");
	return 0;
}

