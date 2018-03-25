#include<stdio.h>
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	double array[n][n];
	int col=n,row=n;
	int times=0;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%lf",&array[i][j]);
	double I[n][n];
	for (i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			if(i==j)
				I[i][j]=1;
			else
				I[i][j]=0;
		}
	for(times=0;times<row;times++)
	{
		for(k=0;k<row;k++)
		{
			double temp = 0;
			temp = array[k][times]/array[times][times];
			if(k==times)
				continue;
			for(l=0;l<col;l++)
			{
				array[k][l]-=array[times][l]*temp;
				I[k][l]-=I[times][l]*temp;
			}
		}
	}
	i=0;
	for(i=0;i<n;i++)
	{
		
		if(array[i][i]!=1)
		{
			int temp1=array[i][i];
			array[i][i]/=array[i][i];
			for(j=0;j<n;j++)
			{
				I[i][j]/=temp1 ;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%lf",I[i][j]);
	}
	return 0;

}


		



