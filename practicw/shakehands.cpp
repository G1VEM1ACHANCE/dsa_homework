#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int array[a][a];
    memset(array,0,a*a*sizeof(int));
    for(int i=0;i<b;i++)
    {
        int person1,person2;
        scanf("%d%d",&person1,&person2);
        if(person1<0||person2<0||person1>=a||person2>=a)
            continue;
        array[person1][person2]=1;
        array[person2][person1]=1;
    }
    for(int k=0;k<c;k++)
    {
        int person3,person4;
        scanf("%d %d",&person3,&person4);
        if(person3<0||person4<0||person3>=a||person4>=a)
            continue;
        if(array[person3][person4]==1)
            printf("yes\n");
        else printf("no\n");
    }
}
