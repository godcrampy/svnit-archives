#include <stdio.h>
#include <sys/poll.h>
#include <unistd.h>

#define TIMEOUT 5000

int main(void) {
  struct pollfd fds[3];
  int ret;

  /* watch stdin for input */
  fds[0].fd = STDIN_FILENO;
  fds[0].events = POLLIN;

  /* watch stdout for ability to write */
  fds[1].fd = STDOUT_FILENO;
  fds[1].events = POLLOUT;

  /* watch stderr for ability to write */
  fds[2].fd = STDERR_FILENO;
  fds[2].events = POLLERR;

  ret = poll(fds, 3, TIMEOUT * 1000);

  if (ret == -1) {
    perror("poll");
    return 1;
  }

  if (!ret) {
    printf("%d seconds elapsed.\n", TIMEOUT);
    return 0;
  }

  if (fds[0].revents & POLLIN) {
    printf("stdin is readable\n");
  }

  if (fds[1].revents & POLLOUT) {
    printf("stdout is writable\n");
  }

  if (fds[2].revents & POLLERR) {
    printf("stderr is writable\n");
  }

  return 0;
}