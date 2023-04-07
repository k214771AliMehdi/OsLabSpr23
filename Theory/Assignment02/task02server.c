#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int num_clients = 0;
int client_sockets[MAX_CLIENTS];

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            // error or connection closed by client
            printf("Client %d disconnected\n", client_socket);
            close(client_socket);
            pthread_exit(NULL);
        }
        // null-terminate received data
        buffer[bytes_received] = '\0';
        // print received message
        printf("Received message from client %d: %s", client_socket, buffer);
        // send message to all other clients
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, bytes_received, 0);
            }
        }
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(1);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }
    listen(server_socket, 5);
    printf("Server is listening on port 8888...\n");
    while (1) {
        // accept a new client connection
        struct sockaddr_in client_addr;
        int client_addrlen = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addrlen);
        if (client_socket < 0) {
            perror("Failed to accept client connection");
            continue;
        }
        printf("Client %d connected\n", client_socket);
        // add client socket to array of sockets
        client_sockets[num_clients++] = client_socket;
        // create a new thread to handle the client connection
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, &client_socket) != 0) {
            perror("Failed to create thread");
            continue;
        }
    }
    return 0;
}
