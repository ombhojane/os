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
        printf("Parent process is waiting for input:\n");

        // Read data from standard input and write it to the screen
        char buffer[1024];
        fgets(buffer, sizeof(buffer), stdin);
        printf("Parent process received: %s", buffer);
    } else {
        printf("Child process: My PID is %d and my parent's PID is %d\n", getpid(), getppid());
        printf("Child process is waiting for input:\n");

        // Read data from standard input and write it to the screen
        char buffer[1024];
        fgets(buffer, sizeof(buffer), stdin);
        printf("Child process received: %s", buffer);
    }

    return 0;
}
