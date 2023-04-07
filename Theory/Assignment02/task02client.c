#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_ADDRESS, &server_address.sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server %s:%d\n", SERVER_ADDRESS, SERVER_PORT);

    while (1) {
        // Get user input
        printf("Enter a message: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send the message to the server
        send(sockfd, buffer, strlen(buffer), 0);

        // Receive a response from the server
        ssize_t num_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (num_bytes == 0) {
            printf("Server disconnected\n");
            break;
        } else if (num_bytes < 0) {
            perror("recv failed");
            break;
        } else {
            buffer[num_bytes] = '\0';
            printf("Received message: %s", buffer);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}
