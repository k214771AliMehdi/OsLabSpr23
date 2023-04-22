#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_READERS 2
#define NUM_WRITERS 1

pthread_rwlock_t rwlock;
int shared_data = 0;

void* reader(void* arg) {
    int id = *(int*)arg;

    while (1) {
        // acquire read lock
        pthread_rwlock_rdlock(&rwlock);

        // read from shared resource
        printf("Reader %d read shared_data: %d\n", id, shared_data);

        // release read lock
        pthread_rwlock_unlock(&rwlock);

        // wait a bit before reading again
        usleep(500000);
    }

    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;

    while (1) {
        // acquire write lock
        pthread_rwlock_wrlock(&rwlock);

        // update shared resource
        shared_data += 1;
        printf("Writer %d updated shared_data to: %d\n", id, shared_data);

        // release write lock
        pthread_rwlock_unlock(&rwlock);

        // wait a bit before writing again
        usleep(1000000);
    }

    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];

    // initialize the reader-writer lock
    pthread_rwlock_init(&rwlock, NULL);

    // create the reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&readers[i], NULL, reader, id);
    }

    // create the writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&writers[i], NULL, writer, id);
    }

    // join the reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    // join the writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    // destroy the reader-writer lock
    pthread_rwlock_destroy(&rwlock);

    return 0;
}
