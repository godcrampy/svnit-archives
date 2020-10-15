#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    puts("Pass query as argument");
    return 1;
  }
  FILE *f = fopen("data", "r");
  if (f == NULL) {
    puts("ERROR: File not found\n");
    return 1;
  }
  char name[50];
  char marks[50];
  while (fscanf(f, "%s", name) == 1) {
    fscanf(f, "%s", marks);
    if (strcmp(name, argv[1]) == 0) {
      printf("%s %s\n", name, marks);
      fclose(f);
      return 0;
    }
  }
  puts("ERROR: Name not found");
  return 1;
}
