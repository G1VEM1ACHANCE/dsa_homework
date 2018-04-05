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
        printf("%d%s%s%f%f%lld\n",vec[i]->date,vec[i]->currencyname,vec[i]->exchangestore,vec[i]->low,vec[i]->high,vec[i]->cap);
    
}

