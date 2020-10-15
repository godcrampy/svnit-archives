#include <stdio.h>
#include "util.h"
#include "linear-singly-linked-list.h"

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
    if (taskCode == 'i')
    {
      // insertion
      char type = getInsertCode();
      if (type == 'f')
        list = insertFirst(list, getNode());
      if (type == 'l')
        list = insertLast(list, getNode());
      if (type == 'm')
      {
        int position;
        printf("Enter Position: ");
        scanf("%d", &position);
        getchar();
        list = insertAtIndex(list, getNode(), position);
      }
    }
    if (taskCode == 'd')
    {
      // deletion
      char type = getDeleteCode();
      if (type == 'f')
        list = deleteFirst(list);
      if (type == 'l')
        list = deleteLast(list);
      if (type == 'm')
      {
        int position;
        printf("Enter Position: ");
        scanf("%d", &position);
        getchar();
        list = deleteAtIndex(list, position);
      }
    }
    if (taskCode == 's')
    {
      char type = getSearchCode();
      if (type == 'n')
      {
        char name[50];
        printf("Enter Name: ");
        fgets(name, 50, stdin);
        printNode(searchName(list, name));
      }
      if (type == 'r')
      {
        int rollNumber;
        printf("Enter Roll Number: ");
        scanf("%d", &rollNumber);
        getchar();
        printNode(searchRollNumber(list, rollNumber));
      }
      if (type == 'c')
      {
        float cgpa;
        printf("Enter CGPA: ");
        scanf("%f", &cgpa);
        getchar();
        printNode(searchCGPA(list, cgpa));
      }
    }
    if (taskCode == 'p')
    {
      printList(list);
    }
  }
  if (list == NULL)
  {
    printf("List Emptied\n");
    goto start;
  }
  return 0;
}
