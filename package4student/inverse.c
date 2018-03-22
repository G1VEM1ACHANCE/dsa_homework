#include<stdio.h>
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	int array[n][n],col=n,row=n;
	int times=0;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d",&array[i][j]);
	double I[n][n];
	for (i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			if(i==j)
				I[i][j]=1;
			else
				I[i][j]=0;
		}
	for(k=0;k<row;k++)
	{
		if(k=times)
			continue;
		for(l=0;l<col;l++)
		{
			array[k][l]-=array[times][l]*(array[k][times]/array[times][times]);
			I[k][l]-=I[times][l]*(array[k][times]/array[times][times]);
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			printf("%d",array[i][j]);
	return 0;

}


		



