#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(pipefd[0]); // Close reading end

        char message[] = "Hello, child process!";
        printf("Parent process sending message to child process: %s\n", message);
        write(pipefd[1], message, strlen(message) + 1);

        close(pipefd[1]); // Close writing end
    } else { // Child process
        close(pipefd[1]); // Close writing end

        char buffer[BUFFER_SIZE];
        read(pipefd[0], buffer, BUFFER_SIZE);
        printf("Child process received message from parent process: %s\n", buffer);

        close(pipefd[0]); // Close reading end
    }

    return 0;
}
