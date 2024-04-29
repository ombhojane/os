#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 10

int main() {
    int fd_read, fd_write;
    ssize_t num_bytes_read, num_bytes_written;
    char buffer[BUFFER_SIZE];

    fd_read = open("test.txt", O_RDONLY);
    if (fd_read == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    num_bytes_read = read(fd_read, buffer, BUFFER_SIZE);
    if (num_bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    fd_write = open("abc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd_write == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    num_bytes_written = write(fd_write, buffer, num_bytes_read);
    if (num_bytes_written == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    close(fd_read);
    close(fd_write);
    return 0;
}
