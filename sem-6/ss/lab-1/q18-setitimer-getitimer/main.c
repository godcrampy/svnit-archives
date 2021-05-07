#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void sig_handler(int signum) { printf("Alarm Called\n"); }

int main() {

  struct itimerval t, test;

  t.it_interval.tv_sec = 1;
  t.it_interval.tv_usec = 0;
  t.it_value.tv_sec = 1;
  t.it_value.tv_usec = 0;

  signal(SIGALRM, sig_handler);
  setitimer(ITIMER_REAL, &t, NULL);
  getitimer(ITIMER_REAL, &test);

  printf("Timer Set: %d %d\n", test.it_interval.tv_sec, test.it_value.tv_sec);

  while (1) {
    printf("...");
    fflush(stdout);
    sleep(1);
  }
  return 0;
}