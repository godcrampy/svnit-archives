#include "stdio.h"

#define abs(i) ((i) >= 0 ? (i) : -(i))

int main(int argc, char const *argv[]) {
  int x = -4;
  // Should return 3 but returns 2
  printf("Macro expected value: 3\nActual value: %d\n", abs(++x));
  return 0;
}
