#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 1000

int array[MAX_SIZE], temp[MAX_SIZE];

typedef struct {
    int left;
    int right;
} range;

void merge(int left, int mid, int right) {
    int i, j, k;
    for (i = left, j = mid + 1, k = left; i <= mid && j <= right; k++) {
        if (array[i] <= array[j]) {
            temp[k] = array[i++];
        } else {
            temp[k] = array[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = array[i++];
    }
    while (j <= right) {
        temp[k++] = array[j++];
    }
    for (k = left; k <= right; k++) {
        array[k] = temp[k];
    }
}

void *merge_sort(void *data) {
    range *r = (range *) data;
    int left = r->left;
    int right = r->right;
    if (left < right) {
        int mid = (left + right) / 2;

        pthread_t thread_left, thread_right;

        range left_range = {left, mid};
        range right_range = {mid + 1, right};

        pthread_create(&thread_left, NULL, merge_sort, &left_range);
        pthread_create(&thread_right, NULL, merge_sort, &right_range);

        pthread_join(thread_left, NULL);
        pthread_join(thread_right, NULL);

        merge(left, mid, right);
    }
    pthread_exit(NULL);
}

int main() {
    int n, i;
    pthread_t tid;

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    range data = {0, n - 1};

    pthread_create(&tid, NULL, merge_sort, &data);
    pthread_join(tid, NULL);

    printf("Sorted elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
