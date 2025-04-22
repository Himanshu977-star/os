#include <stdio.h>

int main() {
    int i, j = 0, n, a[50], frame[10], no, k, avail, count = 0;

    printf("\nEnter the length of the Reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the number of Frames: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1;

    printf("\nRef String\tPage Frames\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t", a[i]);
        avail = 0;

        for (k = 0; k < no; k++) {
            if (frame[k] == a[i]) {
                avail = 1;
                break;
            }
        }

        if (avail == 0) {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
        }

        for (k = 0; k < no; k++) {
            if (frame[k] != -1)
                printf("%d\t", frame[k]);
            else
                printf("-\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", count);
    return 0;
}
