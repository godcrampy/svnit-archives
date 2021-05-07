#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void communicate(int sockfd) {
  char buff[MAX];
  int n;
  // infinite loop for chat
  for (;;) {
    bzero(buff, MAX);

    // read the message from client and copy it in buffer
    read(sockfd, buff, sizeof(buff));
    // print buffer which contains the client contents
    printf("From client: %sTo client : ", buff);
    bzero(buff, MAX);
    n = 0;
    // copy server message in the buffer
    while ((buff[n++] = getchar()) != '\n')
      ;

    // and send that buffer to client
    write(sockfd, buff, sizeof(buff));

    // if msg contains "Exit" then server exit and chat ended.
    if (strncmp("exit", buff, 4) == 0) {
      printf("Server Exit...\n");
      shutdown(sockfd, SHUT_RDWR);
      break;
    }
  }
}

int main() {
  int sfd, conn_fd, len;
  struct sockaddr_in servaddr, cli;

  // Create Socket
  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd == -1) {
    printf("socket creation failed.\n");
    exit(0);
  } else {
    printf("Socket created.\n");
  }
  bzero(&servaddr, sizeof(servaddr));

  // assign IP, PORT
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  // Binding socket to given IP
  if ((bind(sfd, (SA *)&servaddr, sizeof(servaddr))) != 0) {
    printf("socket bind failed.\n");
    exit(0);
  } else {
    printf("Socket binded.\n");
  }

  struct sockaddr sa;
  int slen = 0;
  getsockname(sfd, &sa, &slen);
  // Now server is ready to listen
  if ((listen(sfd, 5)) != 0) {
    printf("Listen failed.\n");
    exit(0);
  } else
    printf("Server listening.\n");
  len = sizeof(cli);

  // Accept the data packet from client
  conn_fd = accept(sfd, (SA *)&cli, &len);
  if (conn_fd < 0) {
    printf("server acccept failed.\n");
    exit(0);
  } else
    printf("server acccept the client.\n");

  communicate(conn_fd);

  // close the socket
  close(sfd);
}
