#include<stdio.h>
int x[24]={};
int y[24]={};
int z[24]={};
int amount=0;
int temp=0;
int tempmpvalue=0;
//int lagarange=y1*(x-0)(x-x2)/(x1-0)(x1-x2)+y2*(x-0)(x-x1)/(x2-x1)(x2-0);
void find_max_amount(int number)
{
    int flag=0;
    int tempx1=0,tempy1=0,tempx2=0,tempy2=0,templagarange=0;
    int x,y,x1,y1,x2,y2,x3,y3,x4,y4;
    for(int s=0;s<number;s++)
        if(z[s]==0)
            flag++;
    if(flag==0)
        return;
    if(flag<=2){
        int coefficient=y1/((x1-0)*(x1-x2))+y2/((x2-0)*(x2-x1));
        if(coefficient>=0)
        amount++;
        return;
    }
    int temp=0;
    for(int i=0;i<number;i++)
    {
        if(z[i]==1)
            continue;
        x1=x[i];y1=y[i];
        for(int k=i+1;k<number;k++)
        {
            if(z[k]==1)
                continue;
             x2=x[k];y2=y[k];
            int coefficient=y1/((x1-0)*(x1-x2))+y2/((x2-0)*(x2-x1));
            if(coefficient>=0)
                continue;
            int linecount=0;
            for(int j=k+1;j<number;j++)
            {
                if(z[k]==1)
                    continue;
                x=x[j];y=y[j];
                int lagarange=y1*((x-0)*(x-x2))/((x1-0)*(x1-x2))+y2*((x-0)*(x-x1))/((x2-x1)*(x2-0));
                if(lagarange==y&&z[j]==0)
                    linecount++;
            }
            if(linecount>temp)
            {
                temp=linecount;
                amount++;
                tempx1=x1,tempy1=y1;
                tempx2=x2,tempy2=y2;
            }
        }
    }
    for(int i=0;i<number;i++)
    {
        int tempx=x[i];
        templagarange=y1*((tempx-0)*(tempx-tempx2))/((tempx1-0)*(tempx1-tempx2))+y2*((tempx-0)*(tempx-tempx1))/((tempx2-tempx1)*(tempx2-0));
        if(y[i]==templagarange)
            z[i]=1;   
    }
}
int main()
{
    
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
        scanf("%d%d",&x[i],&y[i]);
    find_max_amount(number);
}

