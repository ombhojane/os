#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5

sem_t semaphore;

void *thread_function(void *arg) {
    int id = *((int *)arg);
    printf("Thread %d: Trying to access critical section\n", id);
    sem_wait(&semaphore);
    printf("Thread %d: Entered critical section\n", id);
    sleep(2);
    printf("Thread %d: Exiting critical section\n", id);
    sem_post(&semaphore);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    if (sem_init(&semaphore, 0, 1) != 0) {
        perror("sem_init");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    if (sem_destroy(&semaphore) != 0) {
        perror("sem_destroy");
        exit(EXIT_FAILURE);
    }

    return 0;
}
