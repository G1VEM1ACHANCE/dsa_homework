#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef struct Cryptocurrency
{
    int  date;
    char currencyname[30];
    char exchangestore[30];
    float low;
    float high;
    long long int cap;
}Currency;

bool sort1(Currency *Cur1,Currency *Cur2)
{
    string a1 = Cur1->currencyname;
    string a2 = Cur2->currencyname;
    string b1 = Cur1->exchangestore;
    string b2 = Cur2->exchangestore;
    if (Cur1->date != Cur2->date)
        return Cur1->date < Cur2->date;
    else if(a1 != a2)
        return a1< a2;
    if (a1==a2 && b1!=b2)
        return b1 < b2;
    return false;
    
}
int main(){
    char command[10];
    Currency Currencys;
    Currency Currencies[5];
    Currency *vec[5];
    int i=0;
    for(i=0;i<5;i++)
    {
        scanf("%d%s%s%f%f%lld",&Currencys.date,Currencys.currencyname,Currencys.exchangestore,&Currencys.low,&Currencys.high,&Currencys.cap);
        Currencies[i]=Currencys;
        vec[i]=&Currencies[i];
    }
    stable_sort(begin(vec) ,end(vec),sort1);
    for(i=0;i<5;i++)
        printf("%d %s %s %f %f %lld\n",vec[i]->date,vec[i]->currencyname,vec[i]->exchangestore,vec[i]->low,vec[i]->high,vec[i]->cap);
    while(scanf("%s",command)!=EOF)
    {
        int size=5;
        int first=0;
        int last = size-1;
        char exchangestore2[30],currencyname2[30];
        int date1;
        int flag=0;
        if(strcmp(command,"queries")==0)
        {
            int mid = (first+last)/2;      
            scanf("%d%s%s",&date1,currencyname2,exchangestore2);
            string currencyname1=currencyname2;
            string exchangestore1=exchangestore2;
            string a1=vec[mid]->currencyname;
            string b1=vec[mid]->exchangestore;
            while(first<=last)
            {
                if(first==last)
                {
                    break;
                }
                mid = (first+last)/2; 
                if(date1>vec[mid]->date)
                {
                    first=mid+1;
                }
                if(date1<vec[mid]->date)
                {
                    if(mid==0)
                        last=mid;
                    else
                        last=mid-1;
                }
                if(date1==vec[mid]->date)
                {
                    if(currencyname1>a1)
                    {
                        first=mid+1;
                    }
                    if(currencyname1<a1)
                    {
                        if(mid==0)
                            last=mid;
                        else
                            last=mid-1;
                    }
                    if(currencyname1==a1)
                    {
                        if(exchangestore1>b1)
                        {
                            first=mid+1;
                        }
                        if(exchangestore1<b1)
                        {
                            if(mid==0)
                                last=mid;
                            else
                                last=mid-1;
                        }
                        else
                        {
                            break;                        }
                        
                    }
                }
            }
            if(first==last&&(vec[mid]->date!=date1||vec[mid]->currencyname!=currencyname1||vec[mid]->exchangestore!=exchangestore1))
            {
                printf("none");
                continue;
            }
            else
            {
                printf("%f %f %lld",vec[mid]->low,vec[mid]->high,vec[mid]->cap);
            }
        }
    }
    
}

