#include <stdio.h>

int main(int argc, char const* argv[]) {
  FILE* a = fopen("a", "r");
  if (a == NULL) {
    puts("ERROR: File not found\n");
    return 1;
  }
  FILE* b = fopen("b", "w");
  char c;
  c = fgetc(a);
  while (c != EOF) {
    fputc(c, b);
    c = fgetc(a);
  }
  fclose(a);
  fclose(b);
  return 0;
}
