#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

#define SHM_NAME "/my_shm"
#define SEM_NAME "/my_sem"

typedef struct {
    char message[100];
} shared_data;

int main() {
    sem_t* mutex;
    shared_data* data;
    int shm_fd;

    // Open the semaphore
    mutex = sem_open(SEM_NAME, O_CREAT, 0644, 1);

    // Open the shared memory segment
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0644);

    // Set the size of the shared memory segment
    ftruncate(shm_fd, sizeof(shared_data));

    // Map the shared memory segment into the process's memory space
    data = mmap(NULL, sizeof(shared_data), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Write data to the shared memory segment
    printf("Process 1: Enter message: ");
    scanf("%s", data->message);
    sem_post(mutex);

    // Unmap the shared memory segment from the process's memory space
    munmap(data, sizeof(shared_data));

    // Close the shared memory segment
    close(shm_fd);

    // Close the semaphore
    sem_close(mutex);

    return 0;
}
