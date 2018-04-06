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
bool sort2(Currency *Cur1,Currency *Cur2)
{
    string a1 = Cur1->exchangestore;
    string a2 = Cur2->exchangestore;
    if (Cur1->date != Cur2->date)
        return Cur1->date < Cur2->date;
    else if(a1 != a2)
        return a1< a2;
    return false;
}
int main(){
    char command[10];
    Currency Currencys;
    Currency Currencies[5];
    Currency *vec3[5];
    int i=0;
    for(i=0;i<5;i++)
    {
        scanf("%d%s%s%f%f%lld",&Currencys.date,Currencys.currencyname,Currencys.exchangestore,&Currencys.low,&Currencys.high,&Currencys.cap);
        Currencies[i]=Currencys;
        vec3[i]=&Currencies[i];
    }
    stable_sort(begin(vec3) ,end(vec3),sort2);
    for(i=0;i<5;i++)
        printf("%d %s %s %f %f %lld\n",vec3[i]->date,vec3[i]->currencyname,vec3[i]->exchangestore,vec3[i]->low,vec3[i]->high,vec3[i]->cap);
    while(scanf("%s",command)!=EOF)
    {
        int size=5;
        int first=0;
        int last = size-1;
        char exchangestore2[30];
        int date1;
        char c[4];
        if(strcmp(command,"cap")==0)
        {
            int mid = (first+last)/2;
            scanf("%d%s",&date1,exchangestore2);
            
            string exchangestore1=exchangestore2;
            string a1=vec3[mid]->exchangestore;
            while(first<=last)
            {
                if(first==last)
                {
                    break;
                }
                mid = (first+last)/2;
                if(date1>vec3[mid]->date)
                {
                    first=mid+1;
                }
                if(date1<vec3[mid]->date)
                {
                    if(mid==0)
                        last=mid;
                    else
                        last=mid-1;
                }
                if(date1==vec3[mid]->date)
                {
                    if(exchangestore1>a1)
                    {
                        first=mid+1;
                    }
                    if(exchangestore1<a1)
                    {
                        if(mid==0)
                            last=mid;
                        else
                            last=mid-1;
                    }
                    if(exchangestore1==a1)
                    {
                        break;
                    }
                }
            }
            int i=last,j=first;
            int tempdate=vec3[mid]->date;
            string tempcurrency=vec3[mid]->exchangestore;
            int tempdate1=vec3[i]->date;
            string tempcurrency1=vec3[i]->exchangestore;
            int tempdate2=vec3[j]->date;
            string tempexchangestore2=vec3[j]->exchangestore;
            if(first==last&&(date1!=tempdate||exchangestore1!=tempcurrency))
            {
                printf("none");
                continue;
            }
            else if(first==last)
            {
                printf("%lld",vec3[first]->cap);
                continue;
            }
            while(tempdate!=tempdate2||tempcurrency!=tempexchangestore2)
            {
                j++;
                tempdate2=vec3[j]->date;
                tempexchangestore2=vec3[j]->exchangestore;
            }
            
            while(tempdate!=tempdate1||tempcurrency!=tempcurrency1)
            {
                i--;
                tempdate1=vec3[i]->date;
                tempcurrency1=vec3[i]->exchangestore;
            }
            long long int count=0;
            for(int k=j;k<=i;k++)
                count+=vec3[k]->cap;
            printf("%lld",count);
            
            
        }
    }
}

