#include <stdio.h>
#include <pthread.h>

struct AddArgs {
    int num1;
    int num2;
};

void *add_numbers(void *arg) {
    struct AddArgs *args = (struct AddArgs *)arg;
    int sum = args->num1 + args->num2;
    printf("Sum of %d and %d is %d\n", args->num1, args->num2, sum);
    return NULL;
}

int main() {
    pthread_t thread_id;
    struct AddArgs args = {10, 20};

    if (pthread_create(&thread_id, NULL, add_numbers, &args) != 0) {
        fprintf(stderr, "Failed to create thread\n");
        return 1;
    }

    pthread_join(thread_id, NULL);

    return 0;
}
