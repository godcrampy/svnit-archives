#include <unistd.h>

int main(int argc, char const *argv[]) {
  int *p = sbrk(0);

  brk(p + 4);
  *p = 1;
  return 0;
}
