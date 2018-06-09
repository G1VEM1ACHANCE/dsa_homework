#include<cstdio>
#include<iostream>
int frenchfries[5000];
int days;
int maxdays[5000];
long long int maxways[5000];
int maxtimes=0;
int maxdate=0;
int maxways1=0;
long long int M = 1000000007;
int best_dates[5000]={};
void find_best_dates()
{
    best_dates[maxtimes-1]=maxdate+1;
    int tempmax=maxdate;
    int temp = frenchfries[maxdate];
    int temp1=maxtimes;
    for(int j=temp1;j>0;j--)
    {
        for(int k=tempmax;k>=0;k--)
        {
             if(maxdays[k]==j-1&&frenchfries[k]<=temp)
                 best_dates[j-2]=k+1;
        }
        tempmax=best_dates[j-2];
        temp=frenchfries[tempmax-1];
    }
}

void find_max_days(int k)
{
    maxdays[k]=1;
    for(int i=0;i<k;i++)
        if(frenchfries[i]<=frenchfries[k]&&maxdays[i]+1>maxdays[k])
            maxdays[k]=maxdays[i]+1;
    if(maxdays[k]>maxtimes)
    {
        maxtimes=maxdays[k];
        maxdate=k;
    }
}
void find_max_ways(int k)
{
    if(maxdays[k]==1)
    {
        maxways[k]=1;
        return;
    }
    maxways[k]=0;
    for(int i=0;i<k;i++)
        if(maxdays[i]+1==maxdays[k]&&frenchfries[i]<=frenchfries[k])
        {
            maxways[k]+=maxways[i];  
            maxways[k]%=M;
        }
}

int main()
{ 
    scanf("%d",&days);
    for(int i=0;i<days;i++)
    {
        scanf("%d",&frenchfries[i]);
        find_max_days(i);
        find_max_ways(i);
    }
    int temp=0;
    for(int i=0;i<days;i++)
        if(maxways[maxdate]==maxways[i]&&maxdays[i]==maxdays[maxdate])
        {
            temp+=maxways[i];
            temp%=M;
        }
    find_best_dates();
    printf("%d\n%d\n",maxtimes,temp);
    for(int i=0;i<maxtimes-1;i++)
        printf("%d ",best_dates[i]);
   printf("%d",best_dates[maxtimes-1]); 
}
    
