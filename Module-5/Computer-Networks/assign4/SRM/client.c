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
    int sockfd, i;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    struct Packet packet;
    bool ackReceived[MAX_SEQUENCE_NUMBER + 1] = {false};

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

    int base = 0;
    int nextSeqNum = 0;

    while (base < WINDOW_SIZE) {
        packet.sequenceNumber = nextSeqNum;
        sprintf(packet.data, "Packet %d", nextSeqNum);
        sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&serverAddr, addr_size);
        printf("Sent packet with sequence number: %d\n", packet.sequenceNumber);
        nextSeqNum++;
    }

    while (base < MAX_SEQUENCE_NUMBER) {
        int ack;
        recvfrom(sockfd, &ack, sizeof(int), 0, NULL, NULL);
        printf("Received acknowledgment for packet with sequence number: %d\n", ack);
        if (ackReceived[ack % (MAX_SEQUENCE_NUMBER + 1)] == false) {
            ackReceived[ack % (MAX_SEQUENCE_NUMBER + 1)] = true;
            while (ackReceived[base % (MAX_SEQUENCE_NUMBER + 1)] == true) {
                ackReceived[base % (MAX_SEQUENCE_NUMBER + 1)] = false;
                base++;
                packet.sequenceNumber = nextSeqNum;
                sprintf(packet.data, "Packet %d", nextSeqNum);
                sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&serverAddr, addr_size);
                printf("Sent packet with sequence number: %d\n", packet.sequenceNumber);
                nextSeqNum++;
            }
        }
    }

    close(sockfd);

    return 0;
}

