int SIZE = 4;
int FORKS[SIZE];

init {
  FORKS[0] = 0
  FORKS[1] = 0
  FORKS[2] = 0
  FORKS[3] = 0
  run philosopher(0);
  run philosopher(1);
  run philosopher(2);
  run philosopher(3);
}

proctype philosopher(int i) {
  int low = i, high = (i + 1) % SIZE;

  // Graph based ordering for FORK allocation
  if
  :: (i == SIZE - 1) -> low = (i + 1) % SIZE; high = i;
  :: else low = i; high = (i + 1) % SIZE;
  fi

  do
  :: printf("Philosopher %d is thinking...\n", i + 1);
  (FORKS[low] == 0) -> FORKS[low] = 1; printf("Philosopher %d has picked fork %d...\n", i + 1, low + 1);
  (FORKS[high] == 0) -> FORKS[high] = 1; printf("Philosopher %d has picked fork %d...\n", i + 1, high + 1);
  printf("Philosopher %d is eating...\n", i + 1);
  FORKS[low] = 0;
  FORKS[high] = 0;
  printf("Philosopher %d done eating...\n", i + 1);
  printf("Forks: [%d, %d, %d, %d]\n", FORKS[0], FORKS[1], FORKS[2], FORKS[3])
  od
}
