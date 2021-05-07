#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  struct dirent *de;
  DIR *dr = opendir(".");

  if (dr == NULL) {
    printf("Could not open current directory");
    _exit(1);
  }

  while ((de = readdir(dr)) != NULL) {
    printf("%s\n", de->d_name);
  }
  closedir(dr);
  return 0;
}