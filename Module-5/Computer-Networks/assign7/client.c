
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 12345
#define MAX_MESSAGE_LEN 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Create socket
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_IP, &(server_address.sin_addr)) <= 0) {
        perror("Invalid server IP address");
        exit(EXIT_FAILURE);
    }

    char message[MAX_MESSAGE_LEN];
    while (1) {
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);

        // Send the message to the server
        sendto(client_socket, message, strlen(message), 0, (struct sockaddr*)&server_address, sizeof(server_address));

        // Receive and display the server's reply
        char server_reply[MAX_MESSAGE_LEN];
        socklen_t server_address_len = sizeof(server_address);
        int received_bytes = recvfrom(client_socket, server_reply, sizeof(server_reply), 0, (struct sockaddr*)&server_address, &server_address_len);

        if (received_bytes == -1) {
            perror("Receiving data failed");
            exit(EXIT_FAILURE);
        }

        server_reply[received_bytes] = '\0';
        printf("Server replied: %s\n", server_reply);
    }

    // Close the socket (this part is not reached in this simple example)
    close(client_socket);

    return 0;
}

