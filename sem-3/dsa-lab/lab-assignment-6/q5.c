#include <stdio.h>
#include "q5.h"

int main(int argc, char const *argv[])
{
  printf("\n");
  printf("New List Initialized\n");
  Node *list = (Node *)malloc(sizeof(Node));
  strcpy(list->URL, "home\n");
  list->next = NULL;
  list->previous = NULL;
  printList(list);
  Node *current = list;
  char taskCode = 'a';
  while (taskCode != 'q' && list != NULL)
  {
    taskCode = getTaskCode();
    if (taskCode == 'n')
    {
      Node *temp = getNode();
      current->next = temp;
      temp->previous = current;
      current = current->next;
    }
    if (taskCode == 'b')
    {
      if (current->previous != NULL)
        current = current->previous;
      else
        printf("Cannot Go Back\n");
    }
    if (taskCode == 'f')
    {
      if (current->next != NULL)
        current = current->next;
      else
        printf("Cannot Go Forward\n");
    }
    if (taskCode == 'h')
    {
      printList(list);
    }
    printf("\n\nCurrent URL:\n");
    printNode(current);
  }
  if (list == NULL)
  {
    printf("List Emptied\n");
  }
  return 0;
}
