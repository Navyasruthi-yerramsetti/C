#include<stdio.h>
#include<stdlib.h>
void BestFit(int blockSize[],int m,int processSize[],int n)
{
    int allocation[n];
    for(int i=0;i<n;i++)
        allocation[i]=-1;
    for(int i=0;i<n;i++)
    {
        int bestIdx=-1;
        for(int j=0;j<m;j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                if(bestIdx==-1 || blockSize[j]<blockSize[bestIdx])
                    bestIdx=j;
            }
        }
        if(bestIdx!=-1)
        {
            allocation[i]=bestIdx;
            blockSize[bestIdx]=blockSize[bestIdx]-processSize[i];
        }
    }
    printf("Process No.\t Process Size\tBlock No.\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t",i,processSize[i]);
        if(allocation[i]!=-1)
            printf("%d\n",allocation[i]);
        else
            printf("Not Allocated\n");
    }
}
int main()
{
    int i,bs,p,blockSize[10],processSize[10];
    printf("Enter no.of blocks:");
    scanf("%d",&bs);
    for(i=0;i<bs;i++)
    {
        printf("Enter %d block size:",i);
        scanf("%d",&blockSize[i]);
    }
    printf("Enter no.of process:");
    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        printf("Enter %d process Size:",i);
        scanf("%d",&processSize[i]);
    }
    BestFit(blockSize,bs,processSize,p);
    return 0;
}
