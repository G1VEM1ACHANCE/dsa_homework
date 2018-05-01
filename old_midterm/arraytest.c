#include<stdio.h>
int func(int array[3][3])
{
    array[2][2]=4;
    return 1;
}
int main()
{
    int array[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&array[i][j]);
    int k=func(array);
    for(int i=0;i<3;i++){
        printf("\n");
        for(int j=0;j<3;j++)
            printf("%d",array[i][j]);
    }
    return 0;
}
