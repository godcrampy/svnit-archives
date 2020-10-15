#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    puts("Pass query as argument");
    return 1;
  }
  FILE *f = fopen("data", "r");
  FILE *g = fopen("temp", "w");
  if (f == NULL) {
    puts("ERROR: File not found\n");
    return 1;
  }
  char name[50];
  char marks[50];
  while (fscanf(f, "%s", name) == 1) {
    fscanf(f, "%s", marks);
    if (strcmp(name, argv[1]) == 0) {
      continue;
    }
    fprintf(g, "%s %s\n", name, marks);
  }
  fclose(f);
  fclose(g);

  FILE *a = fopen("temp", "r");
  FILE *b = fopen("data", "w");
  char c;
  c = fgetc(a);
  while (c != EOF) {
    fputc(c, b);
    c = fgetc(a);
  }
  fclose(a);
  fclose(b);
  remove("temp");
  return 0;
}
