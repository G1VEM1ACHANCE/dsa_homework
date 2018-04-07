#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<algorithm>
#include<sstream>
#include<string>
#include<cstring>
#define MAX_size 10000000

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
Currency Currencys[MAX_size];
Currency *vec[MAX_size];
Currency *vec1[MAX_size];
Currency *vec2[MAX_size];
Currency *vec3[MAX_size];
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
bool sort3(Currency *Cur1,Currency *Cur2)
{
    string a1 = Cur1->currencyname;
    string a2 = Cur2->currencyname;
    if (Cur1->date != Cur2->date)
        return Cur1->date < Cur2->date;
    else if(a1 != a2)
        return a1< a2;
    if (a1 == a2 && Cur1->low!=Cur2->low)
        return Cur1->low < Cur2->low;
    return false;
}
bool sort4(Currency *Cur1,Currency *Cur2)
{
    string a1 = Cur1->exchangestore;
    string a2 = Cur2->exchangestore;
    if (Cur1->date != Cur2->date)
        return Cur1->date < Cur2->date;
    else if(a1 != a2)
        return a1< a2;
    return false;
}


//Currency 是用來呼叫structure 
//Currencys strtucture 的名字
int main(int argc, char *argv[])
{
	FILE *fp;
//讀檔
	int i=0;
    char command[10];
    char c[4];
    fp = fopen(argv[1],"r");

	while(!feof(fp))
	{
        fscanf(fp,"%d%s%s%f%f%lld",&Currencys[i].date,Currencys[i].currencyname,Currencys[i].exchangestore,&Currencys[i].low,&Currencys[i].high,&Currencys[i].cap);
        vec[i]=&Currencys[i];
        vec1[i]=&Currencys[i];
        vec2[i]=&Currencys[i];
        vec3[i]=&Currencys[i];
        i++;
    }
      stable_sort(begin(vec) ,begin(vec)+i,sort1);
      stable_sort(begin(vec1) ,begin(vec1)+i,sort2);
      stable_sort(begin(vec2) ,begin(vec2)+i,sort3);
      stable_sort(begin(vec3) ,begin(vec3)+i,sort4);
    while(scanf("%s",command)!=EOF)
    {
        int first=0;
        int last = i-1;
        char exchangestore2[30],currencyname2[30];
        int date1;
        int flag=0;
        if(strcmp(command,"end")==0)
            return 0;
        if(strcmp(command,"query")==0)
        {
            int mid = (first+last)/2;
            scanf("%d%s%s",&date1,currencyname2,exchangestore2);
            string currencyname1=currencyname2;
            string exchangestore1=exchangestore2;
            string a1=vec[mid]->currencyname;
            string b1=vec[mid]->exchangestore;
            while(first<=last)
            {   mid = (first+last)/2;
                a1=vec[mid]->currencyname;
                b1=vec[mid]->exchangestore;
                if(first==last)
                {
                    break;
                }
                
                if(date1>vec[mid]->date)
                {
                    first=mid+1;
                }
                if(date1<vec[mid]->date)
                {
                    if(mid==0)
                        last=mid;
                    else
                        last=mid-1;
                }
                if(date1==vec[mid]->date)
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
                        if(exchangestore1>b1)
                        {
                            first=mid+1;
                        }
                        else if(exchangestore1<b1)
                        {
                            if(mid==0)
                                last=mid;
                            else
                                last=mid-1;
                        }
                        else
                        {
                            break;
                        }
                        
                    }
                }
            }
            if(first==last&&(vec[mid]->date!=date1||vec[mid]->currencyname!=currencyname1||vec[mid]->exchangestore!=exchangestore1))
            {
                printf("none");
                continue;
            }
            else
            {
                printf("%.4f %.4f %lld\n",vec[mid]->low,vec[mid]->high,vec[mid]->cap);
                continue;
            }
        }
        if(strcmp(command,"price")==0)
            scanf("%s",c);
        if(strcmp(command,"price")==0&&strcmp(c,"max")!=0&&strcmp(c,"min")!=0)
        {
            printf("none");
            continue;
        }
        if(strcmp(command,"price")==0&&strcmp(c,"max")==0)
        {
            int mid = (first+last)/2;
            scanf("%d%s",&date1,currencyname2);
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
            printf("%.4f\n",vec1[i]->high);
        }
        if(strcmp(command,"price")==0&&strcmp(c,"min")==0)
        {
            int mid = (first+last)/2;
            scanf("%s%d%s",c,&date1,currencyname2);
            
            string currencyname1=currencyname2;
            string a1=vec2[mid]->currencyname;
            while(first<=last)
            {
                if(first==last)
                {
                    break;
                }
                mid = (first+last)/2;
                if(date1>vec2[mid]->date)
                {
                    first=mid+1;
                }
                if(date1<vec2[mid]->date)
                {
                    if(mid==0)
                        last=mid;
                    else
                        last=mid-1;
                }
                if(date1==vec2[mid]->date)
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
            int i=first;
            int tempdate=vec2[mid]->date;
            string tempcurrency=vec2[mid]->currencyname;
            int tempdate1=vec2[i]->date;
            string tempcurrency1=vec2[i]->currencyname;
            if(first==last&&(date1!=tempdate||currencyname1!=tempcurrency))
            {
                printf("none");
                continue;
            }
            while(tempdate!=tempdate1||tempcurrency!=tempcurrency1)
            {
                i++;
                tempdate1=vec2[i]->date;
                tempcurrency1=vec2[i]->currencyname;
            }
            printf("%.4f\n",vec2[i]->low);
        }
        if(strcmp(command,"cap")==0)
        {
            int mid = (first+last)/2;
            scanf("%d%s",&date1,exchangestore2);
            
            string exchangestore1=exchangestore2;
            string a1=vec3[mid]->exchangestore;
            while(first<=last)
            {   mid = (first+last)/2;
                a1=vec3[mid]->exchangestore;
                if(first==last)
                {
                    break;
                }
                
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
                printf("%lld\n",vec3[first]->cap);
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
            printf("%lld\n",count);
        }
    }

}    
