#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
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
int main(){
Currency Currencys;
vector<Currency> Currencies;
Currencies.reserve(3);
int i=0;
for(i=0;i<5;i++)
{
    scanf("%s%s%s%f%f%lld",Currencys.date,Currencys.currencyname,Currencys.exchangestore,&Currencys.low,&Currencys.high,&Currencys.cap);
    Currencies.push_back(Currencys);
}
printf("%s",Currencies[1].currencyname);
}
