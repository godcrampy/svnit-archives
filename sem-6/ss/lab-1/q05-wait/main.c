#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  if (fork() == 0)
    printf("HC: hello from child\n");
  else {
    printf("HP: hello from parent\n");
    wait(NULL);
    printf("CT: child has terminated\n");
  }

  printf("Bye\n");
  return 0;
}
