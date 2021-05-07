#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd = open("data.txt", O_RDONLY);
  struct stat st;
  fstat(fd, &st);
  int size = st.st_size;
  char *c1 = (char *)calloc(size, sizeof(char));
  char *c2 = (char *)calloc(size, sizeof(char));

  read(fd, c1, size);
  printf("%s\n", c1);

  // Move back to beginning of file
  lseek(fd, 0, SEEK_SET);
  read(fd, c2, size);
  printf("%s", c2);

  close(fd);
  return 0;
}
