#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd = open("./data.txt", O_RDONLY);

  struct stat st;
  fstat(fd, &st);
  int size = st.st_size;

  char *data = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);

  printf("%s", data);
  munmap(data, size);

  return 0;
}
