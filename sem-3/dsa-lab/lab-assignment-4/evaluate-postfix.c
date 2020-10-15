#include <stdio.h>
#include "util.h"

int main(int argc, char **argv)
{
  if (argc == 2)
    printf("%d\n", evaluatePostfix(*(argv + 1)));
  else
    printf("Pass Your Equation as an Argument\n");
  return 0;
}
