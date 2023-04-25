#include <stdio.h>
#include <pthread.h>

#define THREAD_COUNT 3

int choosing[THREAD_COUNT] = {0};
int number[THREAD_COUNT] = {0};

int max_number() {
    int max = number[0];
    int i;
    for (i = 1; i < THREAD_COUNT; i++) {
        if (number[i] > max) {
            max = number[i];
        }
    }
    return max;
}

void *thread_func(void *thread_id) {
    int id = *((int *)thread_id);
    int i;
    choosing[id] = 1;
    number[id] = max_number() + 1;
    choosing[id] = 0;
    int j;
    for (j = 0; j < THREAD_COUNT; j++) {
        while (choosing[j]) {}
        while (number[j] != 0 && (number[j] < number[id] || (number[j] == number[id] && j < id))) {}
    }
    printf("Customer %d is being served by the baker\n", id);
    number[id] = 0;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];
    int i;
    for (i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
