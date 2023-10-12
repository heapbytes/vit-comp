#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

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
    bool received[MAX_SEQUENCE_NUMBER + 1] = {false};

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

    while (1) {
        recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&clientAddr, &addr_size);
        printf("Received packet with sequence number: %d\n", packet.sequenceNumber);

        // Simulate packet loss
        if (rand() % 2 == 0) {
            printf("Packet with sequence number %d lost.\n", packet.sequenceNumber);
            continue;
        }

        // Check if the packet is within the expected window
        if (packet.sequenceNumber >= (MAX_SEQUENCE_NUMBER - WINDOW_SIZE + 1) &&
            packet.sequenceNumber <= MAX_SEQUENCE_NUMBER) {
            // Simulate out-of-order delivery
            if (rand() % 2 == 0) {
                printf("Packet with sequence number %d delivered out of order.\n", packet.sequenceNumber);
                continue;
            }

            // Send an acknowledgment
            printf("Sending acknowledgment for packet with sequence number: %d\n", packet.sequenceNumber);
            sendto(sockfd, &packet.sequenceNumber, sizeof(int), 0, (struct sockaddr*)&clientAddr, addr_size);

            // Mark the packet as received
            received[packet.sequenceNumber] = true;

            // Deliver all sequentially received packets
            while (received[MAX_SEQUENCE_NUMBER - WINDOW_SIZE + 1] == true) {
                received[MAX_SEQUENCE_NUMBER - WINDOW_SIZE + 1] = false;
                // Move the window forward
                for (int i = 0; i < WINDOW_SIZE - 1; i++) {
                    received[i] = received[i + 1];
                }
                // Simulate out-of-order delivery for the next packet
                if (rand() % 2 == 0) {
                    printf("Packet with sequence number %d delivered out of order.\n", MAX_SEQUENCE_NUMBER - WINDOW_SIZE + 2);
                    continue;
                }
                // Send an acknowledgment for the next packet in the window
                printf("Sending acknowledgment for packet with sequence number: %d\n", MAX_SEQUENCE_NUMBER - WINDOW_SIZE + 2);
                sendto(sockfd, &packet.sequenceNumber, sizeof(int), 0, (struct sockaddr*)&clientAddr, addr_size);
            }
        }
    }

    return 0;
}

