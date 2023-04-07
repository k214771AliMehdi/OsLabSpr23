#include <stdio.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define NUM_FILES 3

void* read_file(void* arg) {
    char* filename = (char*)arg;
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        pthread_exit(NULL);
    }
    char buffer[BUFFER_SIZE];
    //char* fgets(char* str, int num, FILE* stream);
    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Process each line of the file here
        printf("%s: %s \n",filename, buffer);
    }
    fclose(file);
    pthread_exit(NULL);
}

int main() {
    pthread_t threadN[NUM_FILES];
    char* filenames[NUM_FILES] = {"file1.txt", "file2.txt", "file3.txt"};
    for (int i = 0; i < NUM_FILES; i++) {
        //(thread number, return, funciton name,func_arg)
        pthread_create(&threadN[i], NULL, read_file, filenames[i]);
    }
    for (int i = 0; i < NUM_FILES; i++) {
        pthread_join(threadN[i], NULL);
        printf("joining done! '%d' \n",threadN[i]);
    }
    return 0;
}
