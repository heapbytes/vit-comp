#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1)
    {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connection
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
    if (client_socket == -1)
    {
        perror("Accepting connection failed");
        exit(EXIT_FAILURE);
    }

    // Read and write the file
    char buffer[BUFFER_SIZE];
    FILE *file = fopen("sample.txt", "rb");
    if (!file)
    {
        perror("File not found");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
        if (bytesRead <= 0)
        {
            break;
        }
        write(client_socket, buffer, bytesRead);
    }

    printf("File sent successfully.\n");

    // Close sockets and file
    close(client_socket);
    close(server_socket);
    fclose(file);

    return 0;
}

