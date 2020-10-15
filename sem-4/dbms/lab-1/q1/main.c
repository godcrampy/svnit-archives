#include <stdio.h>

int main(int argc, char const *argv[]) {
  FILE *f = fopen("file", "r");
  char data[50];
  if (f == NULL) {
    puts("ERROR: File not found\n");
    return 1;
  }
  char c = fgetc(f);
  while (c != EOF) {
    putchar(c);
    c = fgetc(f);
  }
  fclose(f);
  return 0;
}
