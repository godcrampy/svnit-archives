#ifndef _SORTS_H_
#define _SORTS_H_

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int *array, int length)
{
  for (int i = length - 1; i >= 0; --i)
    for (int j = 0; j < i; ++j)
      if (*(array + j) > *(array + j + 1))
        swap(array + j, array + j + 1);
}

void selection_sort(int *array, int length)
{
  for (int i = 0; i < length; ++i)
  {
    // i is the first index of the unsorted array
    int min = *(array + i);
    int min_index = i;
    for (int j = i; j < length; ++j)
      if (*(array + j) < min)
      {
        min = *(array + j);
        min_index = j;
      }
    swap(array + i, array + min_index);
  }
}

#endif