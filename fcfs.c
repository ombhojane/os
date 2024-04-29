#include <stdio.h>

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void fcfs(struct Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    int current_time = 0;

    for (int i = 0; i < n; ++i) {
        if (current_time >= processes[i].arrival_time) {
            processes[i].waiting_time = current_time - processes[i].arrival_time;
        } else {
            processes[i].waiting_time = 0;
            current_time = processes[i].arrival_time;
        }
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i + 1;
    }

    fcfs(processes, n);

    return 0;
}
