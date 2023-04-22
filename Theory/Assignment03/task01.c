#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 10

// Global variables
int buffer[BUFFER_SIZE];
int in_index = 0;
int out_index = 0;
sem_t empty_slots;    // Semaphore for empty slots in the buffer
sem_t full_slots;     // Semaphore for full slots in the buffer
sem_t mutex;          // Semaphore for mutual exclusion

// Producer function that generates random numbers and stores them in the buffer
void *producer(void *arg)
{
    int item;
    while (1) {
        // Generate a random number
        item = rand() % 1000 + 1;
        // Wait for an empty slot in the buffer
        sem_wait(&empty_slots);
        // Obtain the mutex lock to access the buffer
        sem_wait(&mutex);
        // Add the item to the buffer
        buffer[in_index] = item;
        // Update the input index
        in_index = (in_index + 1) % BUFFER_SIZE;
        // Release the mutex lock
        sem_post(&mutex);
        // Signal that a slot in the buffer is full
        sem_post(&full_slots);
        // Sleep for a random amount of time before generating another number
        usleep(rand() % 1000000 + 100000);
    }
    return NULL;
}

// Consumer function that retrieves the numbers from the buffer and prints them on the screen
void *consumer(void *arg)
{
    int item;
    while (1) {
        // Wait for a full slot in the buffer
        sem_wait(&full_slots);
        // Obtain the mutex lock to access the buffer
        sem_wait(&mutex);
        // Retrieve the item from the buffer
        item = buffer[out_index];
        // Update the output index
        out_index = (out_index + 1) % BUFFER_SIZE;
        // Release the mutex lock
        sem_post(&mutex);
        // Signal that an empty slot in the buffer is available
        sem_post(&empty_slots);
        // Print the retrieved item
        printf("%d\n", item);
        // Sleep for a random amount of time before retrieving another number
        usleep(rand() % 1000000 + 100000);
    }
    return NULL;
}

int main()
{
    // Initialize the semaphores
    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full_slots, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create the producer and consumer threads
    pthread_t prod_thread, cons_thread;
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Wait for the threads to complete (which should never happen)
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Destroy the semaphores
    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);
    sem_destroy(&mutex);

    return 0;
}
