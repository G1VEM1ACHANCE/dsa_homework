#include<cstdio>
#include<iostream>
#include<bitset>
using namespace std;
int Evaluate(int array[5][5])
{
    int countO=0,countX=0;
    int countO1=0,countX1=0;
    for(int i=0;i<5;i++){
        countO=0;countX=0;
        for(int j=0;j<5;j++)
        {
            if(array[i][j]==-1)
                countX++;
            if(array[i][j]==1)
                countO++;
        }
        if(countO>=4)
            countO1++;
        if(countX>=4)
            countX1++;
    }
    for(int j=0;j<5;j++){
        countO=0;countX=0;
        for(int i=0;i<5;i++)
        {
            if(array[i][j]==-1)
                countX++;
            if(array[i][j]==1)
                countO++;
        }
        if(countO>=4)
            countO1++;
        if(countX>=4)
            countX1++;
    }
    countO=0;countX=0;
    for(int i=0,j=0;i<5&&j<5;i++,j++)
    {
        if(array[i][j]==-1)
            countX++;
        if(array[i][j]==1)
            countO++;
    }
    if(countO>=4)
        countO1++;
    if(countX>=4)
        countX1++;
    countO=0;countX=0;
    for(int i=0,j=4;i<5&&j>0;i++,j--)
    {
        if(array[i][j]==-1)
            countX++;
        if(array[i][j]==1)
            countO++;
    }
    if(countO>=4)
        countO1++;
    if(countX>=4)
        countX1++;
    if(countX1==countO1)
        return 0;
    else if(countX1>countO1)
        return -1;
    else
        return 1;
}
int whowin(int array[5][5],char round,int count)
{
    if(count==25)
        Evaluate(array);
}
int main(void)
{
    int count = 0;
    long long board=0;
    int times;
    int xturns_taken,oturns_taken;
    char before;
    scanf("%d",&times);
    scanf("%c",&before);
    int array[5][5]={0};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
        {
            scanf("%c",&before);
            if(before=='\n')
                j--;
            if(before=='O')
            {
                board=board << 2;
                array[i][j]=1;
                oturns_taken++;
                board+=2;
                count++;
            }
            if(before=='X'){
                board=board<<2;
                array[i][j]=-1;
                xturns_taken++;
                board+=1;
                count++;
            }
        }
    }
    printf("%d",Evaluate(array));
}

