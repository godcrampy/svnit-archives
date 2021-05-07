#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  char *args[] = {"./hello", NULL};
  execvp(args[0], args);
  printf("End\n");
  return 0;
}
