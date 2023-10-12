#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main()
{
    int client_socket;
    struct sockaddr_in server_address;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_IP, &(server_address.sin_addr)) <= 0)
    {
        perror("Invalid server IP address");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Receive and save the file
    char buffer[BUFFER_SIZE];
    FILE *file = fopen("sample.txt", "wb");
    if (!file)
    {
        perror("File creation failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int bytesRead = read(client_socket, buffer, BUFFER_SIZE);
        if (bytesRead <= 0)
        {
            break;
        }
        fwrite(buffer, 1, bytesRead, file);
    }

    printf("File received successfully.\n");

    // Close socket and file
    close(client_socket);
    fclose(file);

    return 0;
}

