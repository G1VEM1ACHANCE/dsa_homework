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
        string a1 = Cur1->currencyname;
        string a2 = Cur2->currencyname;
        if (Cur1->date != Cur2->date)
            return Cur1->date < Cur2->date;
        else if(a1 != a2)
            return a1< a2;
        if (a1 == a2 && Cur1->high!=Cur2->high)
            return Cur1->high < Cur2->high;
        return false;                                        
}
int main(){
    char command[10];
    Currency Currencys;
    Currency Currencies[5];
    Currency *vec1[5];
    int i=0;
    for(i=0;i<5;i++)
    {
        scanf("%d%s%s%f%f%lld",&Currencys.date,Currencys.currencyname,Currencys.exchangestore,&Currencys.low,&Currencys.high,&Currencys.cap);
        Currencies[i]=Currencys;
        vec1[i]=&Currencies[i];
    }
    stable_sort(begin(vec1) ,end(vec1),sort2);

    while(scanf("%s",command)!=EOF)
    {
        int size=5;
        int first=0;
        int last = size-1;
        char currencyname2[30];
        int date1;
        char c[4];
      
        if(strcmp(command,"price")==0)
        {
            int mid = (first+last)/2;
            scanf("%s%d%s",c,&date1,currencyname2);
            string currencyname1=currencyname2;
            string a1=vec1[mid]->currencyname;
            
           while(first<=last)
            {
                mid = (first+last)/2;
                 a1=vec1[mid]->currencyname;
                if(first==last)
                {
                    break;
                }
                
                if(date1>vec1[mid]->date)
                {
                    first=mid+1;
                }
                if(date1<vec1[mid]->date)
                {
                    if(mid==0)
                        last=mid;
                    else
                        last=mid-1;
                }
                if(date1==vec1[mid]->date)
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
                        break;
                    }
                }
               
            }
     
            int i=last;
            int tempdate=vec1[mid]->date;
            string tempcurrency=vec1[mid]->currencyname;
            int tempdate1=vec1[i]->date;
            string tempcurrency1=vec1[i]->currencyname;
            if(first==last&&(date1!=tempdate||currencyname1!=tempcurrency))
            {
                printf("none");
                continue;
            }
            while(tempdate!=tempdate1||tempcurrency!=tempcurrency1)
            {
                i--;
                tempdate1=vec1[i]->date;
                tempcurrency1=vec1[i]->currencyname;
            }
            printf("%f",vec1[i]->high);

            
        }
    }
}

