#include<stdio.h>
int main()
{
	int blocks,times;
	scanf("%d%d",&blocks,&times);
	int array[blocks];
	for(int i=0;i<blocks;i++)
		scanf("%d",&array[i]);
	for(int i=0;i<times;i++)
	{
		int blockstart,blockend;
		int points=0;
		scanf("%d%d",&blockstart,&blockend);
		for(int k=blockstart-1;k<blockend;k++)
			points+=array[k];
		printf("%d\n",points);
	}
	return 0;
}
