#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef struct Cryptocurrency
{
    char  date[8];
    char currencyname[30];
    char exchangestore[30];
    float low;
    float high;
    long long cap;
}Currency;

bool sort1(Currency *Cur1,Currency *Cur2)
{
    if (Cur1->date < Cur2->date)
        return true;
    else if (Cur1->date > Cur2->date)
        return false;
    else if(Cur1->currencyname > Cur2->currencyname)
        return false;
    else if(Cur1->currencyname < Cur2->currencyname)
        return true;
    else if(Cur1->exchangestore < Cur2->exchangestore)
        return true;
    return false;
}
int main(){
Currency Currencys;
vector<Currency> Currencies;
Currencies.reserve(3);
vector<Currency *> vec;
vec.reserve(3);
vector<Currency *> vec1;
vec1.reserve(3);
int i=0;
for(i=0;i<5;i++)
{
    scanf("%s%s%s%f%f%lld",Currencys.date,Currencys.currencyname,Currencys.exchangestore,&Currencys.low,&Currencys.high,&Currencys.cap);
    Currencies.push_back(Currencys);
    vec[i]=&Currencies[i];
}
printf("%s\n",vec[1]->date);
stable_sort(vec.begin(),vec.end(),sort1);
for(i=0;i<5;i++)
    printf("%s\n",vec[i]->exchangestore);
   
}
