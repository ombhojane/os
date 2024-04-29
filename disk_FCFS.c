#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

void fcfs(int requests[], int num_requests, int initial_position) {
    int total_movement = 0;
    int current_position = initial_position;

    printf("Seek Sequence using FCFS:\n");
    printf("%d ", current_position);

    for (int i = 0; i < num_requests; ++i) {
        total_movement += abs(current_position - requests[i]);
        current_position = requests[i];
        printf("%d ", current_position);
    }

    printf("\nTotal Head Movement: %d\n", total_movement);
}

int main() {
    int num_requests;
    int requests[MAX_REQUESTS];
    int initial_position;

    printf("Enter the number of requests: ");
    scanf("%d", &num_requests);

    printf("Enter the requests: ");
    for (int i = 0; i < num_requests; ++i) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &initial_position);

    fcfs(requests, num_requests, initial_position);

    return 0;
}
