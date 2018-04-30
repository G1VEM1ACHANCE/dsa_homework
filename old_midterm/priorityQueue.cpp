#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int>q;
    int a,i;
    for(i=0;i<4;i++)
    {
        scanf("%d",&a);
        q.push(a);
    }
    for(int i=0;i<4;i++)
    {
        printf("%d",q.top());
        q.pop();
    }
    return 0;
}
        
