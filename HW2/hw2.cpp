#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>

ifstream cryptocurrencyin;
using namespace std;
	struct  Cryptocurrency
	{
		char date[8];
		char currencyname[30];
		char exchangestore[30];
		float low;
		float high;
		long long cap;
	};
int main(void)
{
	FILE *fp;
	fp = fopen("filename.txt");
	if(!fp)
	{
		printf("FAIL TO OPEN\n");
		exit(1);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%f%f% lld")
			



