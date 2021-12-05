#include <stdlib.h>

extern /*@only@*/ int *global;

// only means reference not shared

/*@only@*/ int *foo(/*@only@*/ int *x, int *y, int *z) /*@globals global;@*/ {
  int *m = (int *)malloc(sizeof(int));

  global = y;

  free(x);

  *m = *x;

  return z;
}
