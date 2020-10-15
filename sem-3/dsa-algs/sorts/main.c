#include <stdio.h>

#include "sorts.h"

void print_array(int *array, int length)
{
  for (int i = 0; i < length; ++i)
    printf("%d ", *(array + i));
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int array[] = {78, 46, 3, 1, 56};
  selection_sort(array, 5);
  print_array(array, 5);
  return 0;
}
