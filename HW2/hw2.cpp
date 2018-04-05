#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
#include<string>

using namespace std;
typedef struct  Cryptocurrency
	{
		char date[8];
		char currencyname[30];
		char exchangestore[30];
		float low;
		float high;
		long long int cap;
	} Currency;
bool sort1(Currency *Currency1,Currency *Currency2)
{
    if(Currency1->date < Currency2.date)
        return true;
    else if (Currency1->date > Currency2->date)
        return false;
    else if (Currency1->currencyname < Currency2->currencyname)
        return true;
    else if (Currency1->currencyname > Currency2->currencyname)
        return false;
    else if (Currency1->exchangestore < Currency2->exchangestore)
        return true;
    return false;
}

//Currency 是用來呼叫structure 
//Currencys strtucture 的名字
int main(int argc, char *argv[])
{
	FILE *fp;
//讀檔
	fp = fopen(argv[1],"r");
    Currency Currencys[1000000];
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%f%f%lld",Currencys[i].date,Currencys[i].currencyname,Currencys[i].exchangestore,&Currencys[i].low,&Currencys[i].high,&Currencys[i].cap);
        vec[i]=&Currencys[i];
        i++;
    }
    stable_sort(begin(vec),end(vec),sort1);

			
