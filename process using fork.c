#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid > 0) {
        printf("Parent process: My PID is %d and child's PID is %d\n", getpid(), pid);
    } else {
        printf("Child process: My PID is %d and my parent's PID is %d\n", getpid(), getppid());
    }

    return 0;
}
