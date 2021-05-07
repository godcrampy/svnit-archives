#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void handler(int num) {
  char *buf = "Ctrl C Called!\n";
  int len = strlen(buf);
  write(STDOUT_FILENO, buf, len);
}

int main(int argc, char const *argv[]) {

  struct sigaction sa;
  sa.sa_handler = handler;
  sigaction(SIGINT, &sa, NULL);

  printf("PID: %d\n", getpid());
  while (1) {
    printf("...");
    fflush(stdout);
    sleep(1);
  }
  return 0;
}
