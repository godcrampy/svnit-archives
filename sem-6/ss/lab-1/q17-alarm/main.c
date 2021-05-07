#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void sig_handler(int signum) {
  printf("Alarm Called\n");
  exit(0);
}

int main() {

  signal(SIGALRM, sig_handler);

  alarm(2);

  while (1) {
    printf("...");
    fflush(stdout);
    sleep(1);
  }
  return 0;
}