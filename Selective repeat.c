#include <stdio.h>
int main() {
    int w, n, a[50] = {0}, b = 0, m = 0, i;
    printf("Enter total frames: ");
    scanf("%d", &n);
    printf("Enter window size: ");
    scanf("%d", &w);
    while (b < n) {
        while (m < b + w && m < n)
            printf("Sending frame %d\n", m++);
        for (i = b; i < m; i++)
            if (!a[i - b]) {
                printf("Enter 1 if ACK for frame %d received, 0 if lost: ", i);
                scanf("%d", &a[i - b]);
            }
        while (b < m && a[0]) {
            printf("Frame %d acknowledged. Sliding window.\n", b);
            for (i = 0; i < w - 1; i++) a[i] = a[i + 1];
            a[w - 1] = 0;
            b++;
        }
        for (i = 0; i < w && b + i < m; i++)
            if (!a[i]) printf("Resending frame %d\n", b + i);
    }
    printf("All frames sent successfully.\n");
    return 0;
}
