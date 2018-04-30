#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int workers,times;
    int salary,salarysum=0;
    int totalsum=0;
    priority_queue<int>q;
    scanf("%d%d",&workers,&times);
    for(int i=0;i<workers;i++){
        scanf("%d",&salary);
        salarysum+=salary;
        q.push(salary);
    }
    int operation,salary1;
    for(int i=0;i<times;i++)
    {
        scanf("%d%d",&operation,&salary1);
        if(operation==1){
            q.push(salary1);
            salarysum+=salary1;
        }
        else if(operation==2)
        {
            printf("%d",q.top());
            while(q.top()>salary1){
                salarysum-=q.top();           
                q.pop();
            }
        printf("%d",salarysum);
        }
        totalsum+=salarysum;
    }
    printf("%d",totalsum);
}

