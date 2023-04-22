#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/file.h>

#define FILENAME "example.txt"

int main() {
    int fd;
    pid_t pid;

    fd = open(FILENAME, O_WRONLY | O_APPEND | O_CREAT, 0644);

    pid = fork();

    if (pid == 0) {
        flock(fd, LOCK_EX);
        char* message = "Hello from child process!\n";
        write(fd, message, strlen(message));
        flock(fd, LOCK_UN);
        exit(0);
    }
    else {
        flock(fd, LOCK_EX);
        char* message = "Hello from parent process!\n";
        write(fd, message, strlen(message));
        flock(fd, LOCK_UN);
    }

    close(fd);

    return 0;
}
