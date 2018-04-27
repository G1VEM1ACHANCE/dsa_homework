#include<cstdio>
#include<iostream>
int main(){
	int workers,times;
	int salary[200000];
	int salarysum=0;
	int totalpay=0;
	scanf("%d%d",&workers,&times);
	for(int i=0;i<workers;i++){
		scanf("%d",&salary[i]);
		salarysum+=salary[i];
	}
	for(int i=0;i<times;i++)
	{
		int operation,salary1;
		scanf("%d%d",&operation,&salary1);
		if(operation==1)
		{
			salary[workers]=salary1;
			workers++;
			salarysum+=salary1;
		}
		else if(operation==2)
		{
			for(int k=0;k<workers;k++)
				if(salary[k]>salary1)
					salarysum-=salary[k];
		}
		totalpay+=salarysum;
	}
	
	printf("%d",totalpay);
	return 0;
}
