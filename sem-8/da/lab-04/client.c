#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 80
#define SA struct sockaddr

void func(int sockfd) {
  char buff[MAX];
  int n;
  bzero(buff, sizeof(buff));
  printf("Enter the string : ");
  n = 0;
  while ((buff[n++] = getchar()) != '\n')
    ;
  write(sockfd, buff, sizeof(buff));
}

int main() {
  int sockfd, connfd;
  struct sockaddr_in servaddr, cli;
  int PORT = 8080;
  printf("Enter Port: ");
  scanf("%d", &PORT);
  getchar();


  // socket create and verification
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("socket creation failed...\n");
    exit(0);
  } else
    printf("Socket successfully created..\n");
  bzero(&servaddr, sizeof(servaddr));

  // assign IP, PORT
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(PORT);

  // connect the client socket to server socket
  if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
    printf("connection with the server failed...\n");
    exit(0);
  } else
    printf("connected to the server..\n");

  func(sockfd);

  close(sockfd);
}
