#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define VECTOR_COUNT 3

int main(int argc, char const *argv[]) {
  int fd1 = open("input.txt", O_RDONLY);
  int fd2 = open("output.txt", O_WRONLY);

  struct iovec vec[VECTOR_COUNT];

  struct stat st;
  fstat(fd1, &st);
  int size = st.st_size;

  for (int i = 0; i < VECTOR_COUNT - 1; ++i) {
    vec[i].iov_base = (char *)calloc(size / VECTOR_COUNT, sizeof(char));
    vec[i].iov_len = size / VECTOR_COUNT;
  }
  int rem = (size - (size / VECTOR_COUNT) * (VECTOR_COUNT - 1));
  vec[VECTOR_COUNT - 1].iov_base = (char *)calloc(rem, sizeof(char));
  vec[VECTOR_COUNT - 1].iov_len = rem;

  readv(fd1, vec, VECTOR_COUNT);
  writev(fd2, vec, VECTOR_COUNT);

  for (int i = 0; i < VECTOR_COUNT; ++i) {
    printf("%s", vec[i].iov_base);
  }

  return 0;
}
