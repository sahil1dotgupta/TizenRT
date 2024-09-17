#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define FILENAME "received_data.txt"
FILE* file;
int stop = 0;

static void print_buf(const unsigned char* buf, int len)
{
    for (int i = 0; i < len; i++){
        fprintf(file, "%02x", buf[i]);
    }
    fprintf(file, "\n");
}

void* receive_data(void* sockfd_ptr) {
    int sockfd = *(int*)sockfd_ptr;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    int n;
    socklen_t addr_len = sizeof(servaddr);

    while (!stop) {
        n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, 0, (struct sockaddr *) &servaddr, &addr_len);
        if (n < 0) {
            printf("Receive failed\n");
        } else {
            buffer[n] = '\0';
            printf("Received CSI DATA Success\n");
            print_buf(buffer,n);
        }
    }
    sleep(1);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t addr_len;
    pthread_t recv_thread;
    char message[20];

    if(argc != 3){
        printf("Input Error\n");
        return -1;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Socket creation failed\n");
        return -1;
    }
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Server address setup
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        close(sockfd);
        return -1;
    }
    addr_len = sizeof(server_addr);

    // Send START command
    strncpy(message, "START", 6);
    sendto(sockfd, message, strlen(message), 0, (const struct sockaddr *)&server_addr, addr_len);

    file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    pthread_create(&recv_thread, NULL, receive_data, (void*)&sockfd);

    // Wait for the user to type "stop"
    while (1) {
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';  // Remove newline character

        if (strncmp(message, "STOP", 5) == 0) {
            stop = 1;
            sendto(sockfd, (const char *)message, strlen(message), 0, (const struct sockaddr *) &server_addr, addr_len);
            printf("Stop command sent to server\n");
            break;
        }
    }
    pthread_join(recv_thread, NULL);
    fclose(file);
    close(sockfd);
    return 0;
}