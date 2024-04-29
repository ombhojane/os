
#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completed;
};

void sjf(struct Process processes[], int n) {
    int total_waiting = 0, total_turnaround = 0, min_burst, shortest, time = 0, completed = 0;
    for (int i = 0; i < n; ++i) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].completed = 0;
    }
    while (completed != n) {
        min_burst = 9999;
        shortest = -1;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= time && processes[i].completed == 0) {
                if (processes[i].burst_time < min_burst) {
                    min_burst = processes[i].burst_time;
                    shortest = i;
                }
            }
        }
        if (shortest == -1) {
            time++;
            continue;
        }
        processes[shortest].completed = 1;
        time += processes[shortest].burst_time;
        completed++;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= time && processes[i].completed == 0) {
                processes[i].waiting_time = time - processes[i].arrival_time;
                processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        total_waiting += processes[i].waiting_time;
        total_turnaround += processes[i].turnaround_time;
    }
    float avg_waiting = (float)total_waiting / n;
    float avg_turnaround = (float)total_turnaround / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; ++i) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }
    sjf(processes, n);
    return 0;
}
