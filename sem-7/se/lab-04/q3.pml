int n = 1;

init {
  int x = 5;
  run fact(x);
  (_nr_pr == 1) -> printf("Factorial of %d is: %d\n", x, n);
}

proctype fact(int x) {
  if
  :: x > 1 -> n = n * x; run fact(x - 1);
  :: else;
  fi
}
