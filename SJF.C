#include <stdio.h>

#define MAX 20

int main() {
    int bt[MAX], at[MAX], ft[MAX], wt[MAX], tat[MAX];
    int i, j, n, x = 0, y = 0, z = 0, min = 0, temp1, temp2, k;
    float avg_wt, avg_tat;

    printf("Enter number of processes to be executed:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the burst time for process-%d:\n", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter the arrival time for process-%d:\n", i + 1);
        scanf("%d", &at[i]);
    }

    // Sorting based on arrival times and burst times (SJF-like approach)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j])) {
                temp1 = at[i]; at[i] = at[j]; at[j] = temp1;
                temp2 = bt[i]; bt[i] = bt[j]; bt[j] = temp2;
            }
        }
    }

    for (i = 0; i < n; i++) {
        min += bt[i];
        for (j = i + 1; j < n && at[j] <= min; j++) {
            for (k = j + 1; k < n && at[k] <= min; k++) {
                if (bt[k] < bt[j]) {
                    temp1 = bt[k]; bt[k] = bt[j]; bt[j] = temp1;
                    temp2 = at[k]; at[k] = at[j]; at[j] = temp2;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        x += bt[i];
        ft[i] = x;
        wt[i] = (i == 0) ? 0 : ft[i - 1] - at[i];
        tat[i] = bt[i] + wt[i];
        y += tat[i];
        z += wt[i];
    }

    printf("\nProcess\tAT\tBT\tFT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ft[i], wt[i], tat[i]);
    }

    avg_wt = (float)z / n;
    avg_tat = (float)y / n;
    
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}

