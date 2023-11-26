#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>


void calculateParity(int data[4], int parity[3])
{
    parity[0] = data[0] ^ data[1] ^ data[3];
    parity[1] = data[0] ^ data[2] ^ data[3];
    parity[2] = data[1] ^ data[2] ^ data[3];
}

int main()
{

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Connection failed");
        close(sockfd);
        return 1;
    }

    printf("Enter a 4-bit message: ");
    char m[5];
    scanf("%4s", m);

    int d0 = m[3] - '0';
    int d1 = m[2] - '0';
    int d2 = m[1] - '0';
    int d3 = m[0] - '0';

    int data[4] = {d3, d2, d1, d0};
    int parity[3];
    calculateParity(data, parity);

    int hammingMsg[7];
    hammingMsg[0] = d3;
    hammingMsg[1] = d2;
    hammingMsg[2] = d1;
    hammingMsg[3] = parity[2];
    hammingMsg[4] = d0;
    hammingMsg[5] = parity[1];
    hammingMsg[6] = parity[0];

    printf("\nMessage with Hamming code: ");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", hammingMsg[i]);
    }
    printf("\n");

    send(sockfd, (char *)hammingMsg, sizeof(hammingMsg), 0);
    close(sockfd);

    return 0;
}
