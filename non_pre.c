#include <stdio.h>

struct Process {
    int pid;           // Process ID
    int arrival;       // Arrival time
    int burst;         // Burst time
    int completion;    // Completion time
    int waiting;       // Waiting time
    int turnaround;    // Turnaround time
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process process[n];

    for (int i = 0; i < n; i++) {
        process[i].pid = i + 1; // Process ID starts from 1
        printf("Enter arrival time and burst time for process %d: ", process[i].pid);
        scanf("%d %d", &process[i].arrival, &process[i].burst);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (process[i].arrival > process[j].arrival) {
                struct Process temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    process[0].completion = process[0].arrival + process[0].burst;
    process[0].turnaround = process[0].completion - process[0].arrival;
    process[0].waiting = 0;

    for (int i = 1; i < n; i++) {
        if (process[i].arrival > process[i - 1].completion) {
            process[i].completion = process[i].arrival + process[i].burst;
        } else {
            process[i].completion = process[i - 1].completion + process[i].burst;
        }

        process[i].turnaround = process[i].completion - process[i].arrival;
        process[i].waiting = process[i].turnaround - process[i].burst;
    }

    // Display the results
    printf("\nProcessID | Arrival | Burst | Completion | Waiting | Turnaround\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%9d | %7d | %5d | %10d | %7d | %10d\n",
               process[i].pid,
               process[i].arrival,
               process[i].burst,
               process[i].completion,
               process[i].waiting,
               process[i].turnaround);
    }

    return 0;
}
