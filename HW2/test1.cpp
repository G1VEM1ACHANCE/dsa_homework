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
Currency Currencys[];
int i=0;
for(i=0;i<5;i++)
{
    scanf("%s%s%s%f%f%lld",Currencys[i].date,Currencys[i].currencyname,Currencys[i].exchangestore,&Currencys[i].low,&Currencys[i].high,&Currencys[i].cap);
}
printf("%s",Currencys[4].currencyname);
}
