#include <stdio.h>
#include "q1.h"

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
    if (taskCode == 'r')
      list = reverse_list(list);
  }
  if (list == NULL)
  {
    printf("List Emptied\n");
    goto start;
  }
  return 0;
}
