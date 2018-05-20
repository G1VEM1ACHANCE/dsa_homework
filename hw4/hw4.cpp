#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
const int x = 29;
const long long int y = 100007; 
char target[300000];
int prefix[300000];
char searchfor[300000];
int power[100001];
using namespace std;
map<int , int> mymap[5];
void maketable(int head,int tail)
{
    
    prefix[0]=0;
    int temp=0;
    int k=1;
    int i;
    for(i=head;i<=tail;i++){
        int coefficient=(int)target[i]-'a'+1;
        temp *= x;
        temp += coefficient;
        temp %= y;
        prefix[k]=temp;
        k++;
    }
}

void search(int searchforlength ,int head,int tail)
{
    int times=0;
    int length=tail-head+1;
    int temp=0,temp1;
    for(int i=0;i<searchforlength;i++){
        int coefficient = (int)searchfor[i]-'a'+1;
        temp *= x;
        temp+=coefficient;
        temp %= y;
    }
    for(int k=0;k+searchforlength<=length;k++)
    { 
        temp1=((prefix[k+searchforlength]-(prefix[k]*power[searchforlength]%y)+y)%y);
        if(temp==temp1)
            times++;
    }
    printf("%d \n",times);
}
int main()
{
    int temp1=1;
    for(int i=0;i<100001;i++)
    {
        power[i]=temp1;
        temp1*=x;
        temp1%=y;
    }
    char in;
    int temp=0;
    scanf("%s",target+100000);
    int length=strlen(target+100000);
    int head=100000;
    int tail=head+length-1;
    int times;
    int command;
    char character;
    scanf("%d",&times);
    for(int i=0;i<times;i++)
    {
        scanf("%d",&command);
        if(command==1)
        {
            scanf(" %c",&character);
            head--;
            target[head]=character;
        }
        if(command==2)
        {
            scanf(" %c",&character);
            tail+=1;
            target[tail]=character;
        }
        if(command==3)
        {
            maketable(head,tail);
            scanf("%s",searchfor);
            int searchforlength=strlen(searchfor);
            search(searchforlength,head,tail);
        }
    }
    return 0;
}
