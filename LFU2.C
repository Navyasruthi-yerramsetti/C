#include <stdio.h>

int main() {
    int total_frames, total_pages, hit = 0, pages[25], frame[10] = {-1}, arr[25] = {0}, time[25] = {0};
    
    printf("Enter Total Pages & Frames:\t");
    scanf("%d %d", &total_pages, &total_frames);

    printf("Enter Reference String:\n");
    for (int m = 0; m < total_pages; m++) {
        scanf("%d", &pages[m]);
    }

    for (int m = 0; m < total_pages; m++) {
        arr[pages[m]]++; time[pages[m]] = m;
        int flag = 1, k = frame[0], temp, min_time = 25;

        for (int n = 0; n < total_frames; n++) {
            if (frame[n] == -1 || frame[n] == pages[m]) {
                if (frame[n] == pages[m]) hit++;
                frame[n] = pages[m]; flag = 0; break;
            }
            if (arr[k] > arr[frame[n]]) k = frame[n];
        }

        if (flag) {
            for (int n = 0; n < total_frames; n++) {
                if (arr[frame[n]] == arr[k] && time[frame[n]] < min_time) {
                    temp = n; min_time = time[frame[n]];
                }
            }
            arr[frame[temp]] = 0; frame[temp] = pages[m];
        }

        for (int n = 0; n < total_frames; n++) printf("%d\t", frame[n]);
        printf("\n");
    }

    printf("Page Hit:\t%d\n", hit);
    return 0;
}
