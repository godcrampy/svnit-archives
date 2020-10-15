#include <stdio.h>
#include "q4.h"

int main(int argc, char const *argv[])
{
start:
  printf("\n");
  printf("New List Initialized\n");
  printf("Enter List Data\n");
  Node *list = createList();
  char taskCode = 'a';
  while (taskCode != 'q' && list != NULL)
  {
    taskCode = getTaskCode();
    if (taskCode == 'p')
      printList(list);
    if (taskCode == 's')
    {
      Node *array[2];
      split_list(list, array);
      printList(array[0]);
      printf("END OF LIST 1\n");
      printList(array[1]);
      break;
    }
  }
  if (list == NULL)
  {
    printf("List Emptied\n");
    goto start;
  }
  return 0;
}
