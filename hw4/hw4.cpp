#include<cstdio>
#include<iostream>
#include<unordered_map>
#include<cstring>
const long long int x = 29;
const long long int y = 1000000007; 
char target[300000];
long long int prefix[300000];
char searchfor[300000];
long long int power[100001];
using namespace std;
unordered_map<long long int , long long int> mymap[11];
void makehash(long long int length)
{
    for( int k=1;k<=length;k++)
        for( int j=k;j<k+10&&j<=length;j++) 
        {
            long long int temp1=((prefix[j]-(prefix[k-1]*power[j-k+1]%y)+y)%y);
                mymap[j-k+1][temp1]++;
        }
}
void maketable(long long int head,long long int tail)
{
    prefix[0]=0;
    long long int temp=0;
    long long int k=1;
    long long int i;
    for(i=head;i<=tail;i++){
        long long int coefficient=(long long int)target[i]-'a'+1;
        temp *= x;
        temp += coefficient;
        temp %= y;
        prefix[k]=temp;
        k++;
    }
}

void search(long long int searchforlength ,long long int head,long long int tail)
{
    int times=0;
    long long int length=tail-head+1;
    long long int temp=0,temp1;
    for( int i=0;i<searchforlength;i++){
        int coefficient = (int)searchfor[i]-'a'+1;
        temp *= x;
        temp+=coefficient;
        temp %= y;
    }
    if(searchforlength<=10)
    {
        printf("%lld\n",mymap[searchforlength][temp]);
        return;
    }
    maketable(head,tail);
    for(int k=0;k+searchforlength<=length;k++)
    { 
        temp1=((prefix[k+searchforlength]-(prefix[k]*power[searchforlength]%y)+y)%y);
        if(temp==temp1)
            times++;
    }
    printf("%d\n",times);
}
int main()
{
    long long int temp1=1;
    for(long long int i=0;i<100001;i++)
    {
        power[i]=temp1;
        temp1*=x;
        temp1%=y;
    }
    long long int temp=0;
    scanf("%s",target+100000);
    long long int length=strlen(target+100000);
    long long int head=100000;
    long long int tail=head+length-1;
    int times;
    int command;
    char character;
    maketable(head,tail);
    makehash(tail-head+1); 
    scanf("%d",&times);
    
    for(long long int i=0;i<times;i++)
    {
        length=strlen(target+head);
        scanf("%d",&command);
        long long int temp = 0;
        if(command==1)
        {
            scanf(" %c",&character);
            head--;
            target[head]=character;
            for(int k=0;k<10;k++)
            {
                long long int tempchar = (int)target[head+k]-'a'+1;
                temp *= x;
                temp += tempchar;
                temp %=y;
                mymap[k+1][temp]++; 
            }
        }
        if(command==2)
        {
            scanf(" %c",&character);
            tail+=1;
            target[tail]=character;
            for(long long int k=0;k<10;k++)
            {
                long long int tempchar = (int)target[tail-k]-'a'+1;
                tempchar*=power[k];
                temp+=tempchar;
                temp%=y;
                mymap[k+1][temp]++;
            }
        }
        if(command==3)
        {
            scanf("%s",searchfor);
            long long int searchforlength=strlen(searchfor);
            search(searchforlength,head,tail);
        }
    }
    return 0;
}
