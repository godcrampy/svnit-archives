#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  struct sigaction act, oact;

  sigset_t new_mask;
  sigset_t old_mask;

  /* initialize the new signal mask */
  sigfillset(&new_mask);

  /* block all signals */
  sigprocmask(SIG_SETMASK, &new_mask, &old_mask);

  printf("Can't Kill me for 5 seconds!\n");
  fflush(stdout);
  sleep(5);
  printf("Kill Now!\n");

  /* restore signal mask */
  sigprocmask(SIG_SETMASK, &old_mask, NULL);
  return 0;
}