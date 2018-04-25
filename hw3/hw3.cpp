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
        return -1;//X wins
    else
        return 1;//O wins
}
void printresult(int i)
{
    if(i==1)
        printf("O win");
    if(i==-1)
        printf("X win");
    if(i==0)
        printf("Draw");
    return;
}
int whowin(int array[5][5],char round,int count)
{
    int result;
    int tempcount=0;
    int blank[25][2]={0};
    for(int k=0;k<5;k++)
        for (int l=0; l<5; l++) {
            if(array[k][l]==0){
                blank[tempcount][0]=k;
                blank[tempcount][1]=l;
                tempcount++;
            }
        }
    if(count>=22){
        for(int i=0;i<25-count;i++)
            array[blank[i][0]][blank[i][1]]=-1;
        return Evaluate(array);
    }
    if(round=='X'){
        result = 1;
        for(int i=0;i<tempcount;i++){
            int temp1 = blank[i][0];
            int temp2 = blank[i][1];
            array[temp1][temp2]=-1;
            for(int j=i+1;j<tempcount;j++){
                int temp3 = blank[j][0];
                int temp4 = blank[j][1];
                array[temp3][temp4]=-1;
                int nextresult = whowin(array,'O',count+2);
                array[temp3][temp4]=0;
                if(nextresult==-1)
                    result=-1;
                else if(nextresult == 0 && result == 1)
                    result = 0;
            }
                array[temp1][temp2]=0;
        }
    }
    else if(round=='O')
    {
        result = -1;
        for(int i=0;i<tempcount;i++){
            int temp1 = blank[i][0];
            int temp2 = blank[i][1];
            array[temp1][temp2]=1;
            for(int j=i+1;j<tempcount;j++){
                int temp3 = blank[j][0];
                int temp4 = blank[j][1];
                array[temp3][temp4]=1;
                int nextresult = whowin(array,'X',count+2);
                array[temp3][temp4]=0;
                if(nextresult==1)
                    result=1;
                else if(nextresult == 0 && result == -1)
                    result = 0;
            }
            array[temp1][temp2]=0;
        }
    }
    return result;
}

int main(void)
{
    int count;
    long long board=0;
    int times;
    char before;
    char round;
    scanf("%d",&times);
    for(int s=0;s<times;s++){
        int Ocount = 0;
        int Xcount = 0;
        scanf("%c",&before);
        int array[5][5]={0};
        int k=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++)
            {
                scanf("%c",&before);
                if(before=='\n')
                    j--;
                if(before=='.')
                    array[i][j]=0;
                if(before=='O')
                {
                    board=board << 2;
                    array[i][j]=1;
                    board+=2;
                    Ocount++;
                }
                if(before=='X'){
                    board=board<<2;
                    array[i][j]=-1;
                    board+=1;
                    Xcount++;
                }
            }
        }

        count = Ocount + Xcount;
        if(Xcount==Ocount)
            round='O';
        else if(Ocount>Xcount)
            round='X';
        printresult(whowin(array,round,count));
        printf("\n");
        
    }
}

