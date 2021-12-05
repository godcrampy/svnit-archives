extern void foo(/*@out@*/ int *x);

extern int bar(/*@in@*/ int *x);

extern int baz(int *x);

int func(/*@out@*/ int *x, int i) {
  if (i > 3) return *x;
  if (i > 1) return bar(x);
  if (i == 0) return baz(x);

  foo(x);

  return *x;
}

int main() { return 0; }