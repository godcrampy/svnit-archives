#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  printf("One\n");
  _exit(0);
  printf("Two\n");
  return 0;
}
