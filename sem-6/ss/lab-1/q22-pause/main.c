#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void handler() { printf("Signal caught\n"); }

int main() {
  signal(SIGINT, handler);
  printf("Waiting for your Signal!\n");
  pause();
  printf("Found signal!\n");
  return (0);
}