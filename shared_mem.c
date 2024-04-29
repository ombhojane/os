#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok(".", 's');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    int shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory segment attached at address %p\n", shm_ptr);

    char message[] = "Hello from shared memory!";
    strncpy(shm_ptr, message, strlen(message));

    printf("Content written to shared memory: %s\n", shm_ptr);

    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    return 0;
}
