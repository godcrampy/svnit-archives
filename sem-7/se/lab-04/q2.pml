init {
  int a = 50, b = 70;
  do
  :: a > b -> a = a - b;
  :: b > a -> b = b - a;
  :: a == b -> break;
  od
  printf("GCD: %d\n", a);
}
