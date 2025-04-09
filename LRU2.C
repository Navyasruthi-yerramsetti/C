#include <stdio.h>

int findLRU(int time[], int n) {
    int pos = 0, min = time[0];
    for (int i = 1; i < n; i++)
        if (time[i] < min) min = time[i], pos = i;
    return pos;
}

int main() {
    int frames[10], pages[30], time[10] = {0}, counter = 0, faults = 0;
    int no_of_frames, no_of_pages;

    printf("Enter frames & pages count: ");
    scanf("%d %d", &no_of_frames, &no_of_pages);

    printf("Enter reference string:\n");
    for (int i = 0; i < no_of_pages; i++) scanf("%d", &pages[i]);

    for (int i = 0; i < no_of_frames; i++) frames[i] = -1;

    for (int i = 0; i < no_of_pages; i++) {
        int flag = 0;
        for (int j = 0; j < no_of_frames; j++) {
            if (frames[j] == pages[i]) {
                flag = 1; time[j] = ++counter;
                break;
            }
        }

        if (!flag) {
            int pos = (frames[0] == -1) ? 0 : findLRU(time, no_of_frames);
            frames[pos] = pages[i]; time[pos] = ++counter;
            faults++;
        }

        for (int j = 0; j < no_of_frames; j++) printf("%d\t", frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
