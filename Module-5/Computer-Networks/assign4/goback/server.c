#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define WINDOW_SIZE 4
#define MAX_SEQUENCE_NUMBER 7

struct Packet {
    int sequenceNumber;
    char data[256];
};

int main() {
    int sockfd;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;
    struct Packet packet;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error in socket creation");
        exit(1);
    }
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    
    bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    printf("Server listening on port %d...\n", PORT);
    
    addr_size = sizeof(clientAddr);
    
    int expectedSequenceNumber = 0;
    
    while(1) {
        recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&clientAddr, &addr_size);
        printf("Received packet with sequence number: %d\n", packet.sequenceNumber);
        
        if (rand() % 2 == 0) {
            printf("Packet with sequence number %d lost.\n", packet.sequenceNumber);
            continue;
        }
        

        if (packet.sequenceNumber == expectedSequenceNumber) {
            printf("Sending acknowledgment for packet with sequence number: %d\n", packet.sequenceNumber);
            sendto(sockfd, &packet.sequenceNumber, sizeof(int), 0, (struct sockaddr*)&clientAddr, addr_size);
            expectedSequenceNumber = (expectedSequenceNumber + 1) % (MAX_SEQUENCE_NUMBER + 1);
        }
    }
    
    return 0;
}


