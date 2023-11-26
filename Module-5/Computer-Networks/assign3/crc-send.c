#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


char* generateMessageWithCRC(const char* data, const char* key) {
    char* message = (char*)malloc(strlen(data) + strlen(key) - 1);
    strcpy(message, data);
    strcat(message, "000");
    int keyLength = strlen(key);

    for (int i = 0; i <= strlen(message) - keyLength; ++i) {
        if (message[i] == '1') {
            for (int j = 0; j < keyLength; ++j) {
                message[i + j] = (message[i + j] == key[j]) ? '0' : '1';
            }
        }
    }
    char* result = (char*)malloc(strlen(data) + keyLength);
    strcpy(result, data);
    strcat(result, message + strlen(message) - keyLength + 1);
    free(message);
    return result;
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        perror("Connection failed");
        close(sockfd);
        return 1;
    }
    printf("Enter a 8-bit message: ");
    char data[9];
    scanf("%8s", data);
    const char* key = "1101";

    char* messageWithCRC = generateMessageWithCRC(data, key);

    printf("Generated message with CRC: %s\n", messageWithCRC);

    send(sockfd, messageWithCRC, strlen(messageWithCRC), 0);

    printf("Data sent with CRC: %s\n", messageWithCRC);
    close(sockfd);

    return 0;
}
