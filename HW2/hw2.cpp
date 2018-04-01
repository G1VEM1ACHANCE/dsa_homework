#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<fstream>
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
		long long cap;
	} Currency;
//Currency 是用來呼叫structure 
//Currencys strtucture 的名字
int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(argv[1],"r");
    Currency vector<int>Currencys;
    vec.reserve(50);
    int i=0;
	if(!fp)
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%f%f%lld",Currencys[i].date,Currencys[i].currencyname,Currencys[i].exchangestore,&Currencys[i].low,&Currencys[i].high,&Currencys[i].cap);
    }

			
