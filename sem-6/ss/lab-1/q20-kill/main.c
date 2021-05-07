#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int pid;
  printf("Enter PID to KILL: ");
  scanf("%d", &pid);
  printf("Killing... %d\n", pid);
  kill(pid, SIGINT);
  return 0;
}
