#include <stdio.h>
#include <pthread.h>

void *child_thread_function(void *arg) {
    for (int i = 1; i <= 5; ++i) {
        printf("Child Thread: %d\n", i);
        fflush(stdout);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, child_thread_function, NULL) != 0) {
        fprintf(stderr, "Failed to create thread\n");
        return 1;
    }

    for (int i = 21; i <= 25; ++i) {
        printf("Main Process: %d\n", i);
        fflush(stdout);
    }

    pthread_join(thread_id, NULL);

    return 0;
}
