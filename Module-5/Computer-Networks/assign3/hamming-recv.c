#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
void calculateParity(int data[4], int parity[3]){
    parity[0] = data[0] ^ data[1] ^ data[3];
    parity[1] = data[0] ^ data[2] ^ data[3];
    parity[2] = data[1] ^ data[2] ^ data[3];
}

int main(){
 int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1){
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        perror("Binding failed");
        close(server_socket_fd);
        return 1;
    }

    if (listen(server_socket_fd, 1) == -1){
        perror("Listening failed");
        close(server_socket_fd);
        return 1;
    }

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &client_len);
    if (socket_fd == -1){
        perror("Accepting connection failed");
        close(server_socket_fd);
        return 1;
    }

    int receivedMsg[7];
    recv(socket_fd, (char *)receivedMsg, sizeof(receivedMsg), 0);


    int d3 = receivedMsg[0];
    int d2 = receivedMsg[1];
    int d1 = receivedMsg[2];
    int p2 = receivedMsg[3];
    int d0 = receivedMsg[4];
    int p1 = receivedMsg[5];
    int p0 = receivedMsg[6];

    int receivedData[4] = {d3, d2, d1, d0};
    int receivedParity[3] = {p0, p1, p2};

    int calculatedParity[3];
    calculateParity(receivedData, calculatedParity);

    int errorBit = 0;
    for (int i = 0; i < 3; i++){
        if (receivedParity[i] != calculatedParity[i]){
            errorBit += (1 << i);
        }
    }

    if (errorBit > 0){
        printf("Error detected at bit position: %d\n", errorBit);
        receivedData[errorBit - 1] ^= 1;
    }
    else{
        printf("No Error Detected.");
        printf("\nReceived message: %d %d %d %d\n", receivedData[0], receivedData[1], receivedData[2], receivedData[3]);
    }
    close(socket_fd);
    close(server_socket_fd);
    return 0;
}

