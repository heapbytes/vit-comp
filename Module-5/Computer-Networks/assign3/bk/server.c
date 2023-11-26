#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(6466); 
    serverAddr.sin_addr.s_addr = INADDR_ANY; 

  
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, 5) == -1) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 6466...\n");

    addrSize = sizeof(clientAddr);
    newSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);
    if (newSocket == -1) {
        perror("Accepting connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to client\n");

    
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytesReceived = recv(newSocket, buffer, sizeof(buffer), 0);
        
        if (bytesReceived <= 0) {
            printf("Connection closed by client\n");
            break;
        }

        printf("Client: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Client requested to exit\n");
            break;
        }



        char response[1024];
        printf("Enter response: ");
        fgets(response, sizeof(response), stdin);
        response[strcspn(response, "\n")] = '\0';

        send(newSocket, response, strlen(response), 0);
    }

    close(newSocket);
    close(serverSocket);

    return 0;
}
