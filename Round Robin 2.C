
#include <stdio.h>

int main() {
    int n, quantum, i, time = 0, done = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int at[10], bt[10], rt[10], ct[10];
    for (i = 0; i < n; i++) {
        printf("Enter arrival time of P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while (done < n) {
        int executed = 0;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                if (rt[i] > quantum) {
                    time += quantum;
                    rt[i] -= quantum;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    done++;
                }
                executed = 1;
            }
        }
        if (!executed) time++;
    }

    float totalTAT = 0, totalWT = 0;
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        int tat = ct[i] - at[i];
        int wt = tat - bt[i];
        totalTAT += tat;
        totalWT += wt;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat, wt);
    }

    printf("\nAverage TAT = %.2f\n", totalTAT / n);
    printf("Average WT = %.2f\n", totalWT / n);

    return 0;
}
