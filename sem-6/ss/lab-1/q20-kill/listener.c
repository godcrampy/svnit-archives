#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int pid = getpid();
  printf("PID: %d\n", pid);
  while (1) {
    printf("Running...\n");
    fflush(stdout);
    sleep(1);
  }
  return 0;
}
