#include <stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n) 
{
    int allocation[n];

    for (int i = 0; i < n; i++) 
        allocation[i] = -1;  

    for (int i = 0; i < n; i++) 
    {
        int worstIdx = -1;  

        for (int j = 0; j < m; j++)  
        {
            if (blockSize[j] >= processSize[i]) 
            {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])  
                    worstIdx = j;
            }
        }

        if (worstIdx != -1)  
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];  
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t\t%d\t\t", i, processSize[i]);
        if (allocation[i] != -1) 
            printf("%d\n", allocation[i]);  
        else
            printf("Not Allocated\n");
    }
}

int main()  // Corrected void main() to int main()
{
    int i, bs, p, blockSize[10], processSize[10];  

    printf("Enter no. of blocks: ");
    scanf("%d", &bs);  

    for (i = 0; i < bs; i++)  
    {
        printf("Enter block size %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter no. of processes: ");
    scanf("%d", &p);  

    for (i = 0; i < p; i++) 
    {
        printf("Enter process size %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    worstFit(blockSize, bs, processSize, p);

    return 0;  
}
