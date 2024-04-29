#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 10

int main() {
    int fd;
    ssize_t num_bytes;
    char buffer[BUFFER_SIZE + 1];

    fd = open("xyz.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    num_bytes = read(fd, buffer, BUFFER_SIZE);
    if (num_bytes == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[num_bytes] = '\0';

    printf("First 10 characters of the file:\n%s\n", buffer);

    close(fd);
    return 0;
}
