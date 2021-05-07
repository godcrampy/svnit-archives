#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd1 = open("./data.txt", O_RDONLY);
  int fd2 = open("./copy.txt", O_WRONLY);

  if(fd1 < 0 || fd2 < 0) {
    printf("Cannot open files\n");
    exit(1);
  }

  struct stat st;
  fstat(fd1, &st);
  int size = st.st_size;

  char *c = (char *)calloc(size, sizeof(char));

  read(fd1, c, size);
  printf("%s", c);
  write(fd2, c, size);

  close(fd1);
  close(fd2);
  free(c);
  return 0;
}
