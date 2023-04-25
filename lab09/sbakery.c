#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int choosing[100] = {0};
int number[100] = {0};
pthread_mutex_t lock;
int max_number(int n) {
    int max = number[0];
    int i;
    for (i = 1; i < n; i++) {
        if (number[i] > max) {
            max = number[i];
        }
    }
    return max;
}

void *thread_func(void *thread_id) {
    int id = *((int *)thread_id);
    int i;
    
    pthread_mutex_lock(&lock);
    choosing[id] = 1;
    number[id] = max_number(100) + 1;
    choosing[id] = 0;
    pthread_mutex_unlock(&lock);
    
    int j;
    for (j = 0; j < 100; j++) {
        while (choosing[j]) {}
        while (number[j] != 0 && (number[j] < number[id] || (number[j] == number[id] && j < id))) {}
    }
    //printf("Thread %d entered critical section\n", id);
    number[id] = 0;
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number of threads>\n", argv[0]);
        return 1;
    }
    clock_t start, end;
    start = clock();
    int n = atoi(argv[1]);
    pthread_t threads[n];
    int thread_ids[n];
    int i;

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < n; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    end = clock();
    /* Get the time taken by program to execute in seconds */
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
     
    printf("%f", duration);
    pthread_mutex_destroy(&lock);

    return 0;
}
