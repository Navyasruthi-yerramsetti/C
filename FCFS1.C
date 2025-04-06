#include<stdio.h>

int main()
{
    int at[10], bt[10], wt[10], ft[10], tat[10], i, j, n, temp1, temp2, x = 0;
    int twt = 0, ttat = 0;
    float awt1, atat1;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Sorting arrival times and burst times\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                temp1 = at[i];
                at[i] = at[j];
                at[j] = temp1;

                temp2 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp2;
            }
        }
    }

    printf("Sorted Arrival and Burst Times:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival: %d, Burst: %d\n", at[i], bt[i]);
    }

    printf("Calculating finishing time, waiting time, turn around time\n");
    for (i = 0; i < n; i++) {
        x += bt[i];
        ft[i] = x;
        wt[i] = ft[i] - (at[i] + bt[i]);
        tat[i] = ft[i] - at[i];
        printf("Process %d -> Finishing Time: %d, Waiting Time: %d, Turnaround Time: %d\n", i + 1, ft[i], wt[i], tat[i]);
    }

    for (i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
    }

    awt1 = (float)twt / n;
    atat1 = (float)ttat / n;

    printf("Average Waiting Time: %.2f\n", awt1);
    printf("Average Turn Around Time: %.2f\n", atat1);

    return 0;
}
