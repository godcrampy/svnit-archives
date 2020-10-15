#include <stdio.h>
#include "hash-table.h"

void print_map(int map[])
{
  for (int i = 0; i < 10; ++i)
    printf("%d\n", map[i]);
}

void insert_data(int map[], int data)
{
  int position = hash(data);
  if (map[position] == -1)
  {
    map[position] = data;
    return;
  }
  int iterator = position + 1;
  while (iterator != position)
  {
    if (map[iterator] == -1)
    {
      map[iterator] = data;
      return;
    }
    iterator += 1;
    iterator %= 10;
  }
  printf("NO SPACE LEFT\n");
}

void find_data(int map[], int data)
{
  int position = hash(data);
  if (map[position] == data)
  {
    printf("FOUND!\n");
    return;
  }
  int iterator = position + 1;
  while (iterator != position)
  {
    if (map[iterator] == data)
    {
      printf("FOUND!\n");
      return;
    }
    iterator += 1;
    iterator %= 10;
  }
  printf("NOT FOUND\n");
}

int main(int argc, char const *argv[])
{
  int table[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  print_map(table);
  insert_data(table, 4);
  insert_data(table, 14);
  find_data(table, 5);
  find_data(table, 4);
  find_data(table, 24);
  return 0;
}
