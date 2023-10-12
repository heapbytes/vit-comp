#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define WINDOW_SIZE 4

struct Packet {
    int sequenceNumber;
    char data[256];
};

int main() {
    int sockfd, i;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    struct Packet packet;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error in socket creation");
        exit(1);
    }
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    
    addr_size = sizeof(serverAddr);
    
    for (i = 0; i < WINDOW_SIZE; i++) {
        packet.sequenceNumber = i;
        sprintf(packet.data, "Packet %d", i);
        sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&serverAddr, addr_size);
        printf("Sent packet with sequence number: %d\n", packet.sequenceNumber);
    }
    
    int ack;
    for (i = 0; i < WINDOW_SIZE; i++) {
        recvfrom(sockfd, &ack, sizeof(int), 0, NULL, NULL);
        printf("Received acknowledgment for packet with sequence number: %d\n", ack);
    }
    
    close(sockfd);
    
    return 0;
}

