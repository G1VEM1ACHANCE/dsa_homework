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
		int date;
		char currencyname[30];
		char exchangestore[30];
		float low;
		float high;
		long long int cap;
	} Currency;
//Currency 是用來呼叫structure 
//Currencys strtucture 的名字
int main(int argc, char *argv[])
{
	FILE *fp;
//讀檔
	int i=0;
    fp = fopen(argv[1],"r");
    Currency Currencys[5];
    Currency *vec[5];
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%f%f%lld",&Currencys[i].date,Currencys[i].currencyname,Currencys[i].exchangestore,&Currencys[i].low,&Currencys[i].high,&Currencys[i].cap);
        vec[i]=&Currencys[i];
        i++;
    }

    for(i=0;i<5;i++)
            printf("%d %s %s %f %f %lld\n",vec[i]->date,vec[i]->currencyname,vec[i]->exchangestore,vec[i]->low,vec[i]->high,vec[i]->cap);
}    
