#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 16
char *msg1 = "Message 1";
char *msg2 = "Message 2";
char *msg3 = "Message 3";

int main() {
  char inbuf[MSGSIZE];
  int p[2], i;

  if (pipe(p) < 0)
    exit(EXIT_FAILURE);

  write(p[1], msg1, MSGSIZE);
  write(p[1], msg2, MSGSIZE);
  write(p[1], msg3, MSGSIZE);

  for (i = 0; i < 3; i++) {
    read(p[0], inbuf, MSGSIZE);
    printf("% s\n", inbuf);
  }
  return 0;
}