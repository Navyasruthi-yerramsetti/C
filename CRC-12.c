#include <stdio.h>
int main() {
    int d[100], r[100], g[] = {1,1,0,0,0,0,0,0,0,1,1,1,1};
    int n, i, j;    
    printf("Enter data bits: ");
    scanf("%d", &n);
    printf("Enter data: ");
    for(i = 0; i < n; i++) scanf("%d", &d[i]);
    for(i = 0; i < n + 12; i++) 
        if (i < n)
             r[i] = d[i];
       else
             r[i] = 0;
    for(i = 0; i < n; i++) {
        if(r[i]) {
            for(j = 0; j < 13; j++) 
                r[i+j] ^= g[j];
        }
    }
    
    printf("CRC bits: ");
    for(i = n; i < n + 12; i++) printf("%d", r[i]);
    
    printf("\nTransmitted: ");
    for(i = 0; i < n; i++) printf("%d", d[i]);
    for(i = n; i < n + 12; i++) printf("%d", r[i]);
    
    return 0;
}
