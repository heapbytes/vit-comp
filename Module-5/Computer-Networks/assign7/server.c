#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345
#define MAX_MESSAGE_LEN 1024

int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create socket
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);

    char message[MAX_MESSAGE_LEN];
    while (1) {
        int received_bytes = recvfrom(server_socket, message, sizeof(message), 0, (struct sockaddr*)&client_address, &client_address_len);
        if (received_bytes == -1) {
            perror("Receiving data failed");
            exit(EXIT_FAILURE);
        }

        message[received_bytes] = '\0';
        printf("Received from %s:%d: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), message);

        
        char reply_message[] = "Hello from the server with message as -  ";
        strcat(reply_message, message);
        sendto(server_socket, reply_message, strlen(reply_message), 0, (struct sockaddr*)&client_address, client_address_len);
    }

    // Close the socket (this part is not reached in this simple example)
    close(server_socket);

    return 0;
}

