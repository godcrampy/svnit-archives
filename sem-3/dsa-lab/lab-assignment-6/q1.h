#ifndef UTIL_H
#define UTIL_H 1
#include <stdio.h>
#include <stdlib.h>

// ASSUMPTION: 1 Index Linked List

typedef struct node
{
  int data;
  struct node *previous;
  struct node *next;
} Node;

int isInRange(int number, int left, int right)
{
  // works
  return left <= number && right >= number;
}

int getYesNo(char *message)
{
  // works
  // keeps asking user of either yes or no and returns the boolean value
  char c = 'a';
  while (1)
  {
    printf("%s", message);
    scanf(" %c", &c);
    getchar(); // To clean the buffer
    if (c == 'y' || c == 'Y' || c == '1')
      return 1;
    if (c == 'n' || c == 'N' || c == '0')
      return 0;
  }
}

char getTaskCode()
{
  // works
  printf("Choose next task\n");
  printf("'p' for Print\n");
  printf("'r' for Reverse\n");
  printf("'q' for Quitting\n");
  char c = 'a';
  while (1)
  {
    printf("Enter Command: ");
    scanf(" %c", &c);
    getchar(); // To clean the buffer
    if (c == 'r' || c == 'R')
      return 'r';
    if (c == 'p' || c == 'P')
      return 'p';
    if (c == 'q' || c == 'Q')
      return 'q';
  }
}

Node *getNode()
{

  // gets the data from the user and returns a node pointer
  Node *final = (Node *)malloc(sizeof(Node));
  printf("Enter Data: ");
  scanf("%d", &final->data);
  getchar(); // To clean the buffer
  final->next = NULL;
  final->previous = NULL;
  return final;
}

void printNode(Node *node)
{
  // works
  // prints the node data
  if (node == NULL)
    printf("NOT FOUND\n");
  else
  {
    printf("=======================\n");
    printf("Name: %d\n", node->data);
    printf("=======================\n");
  }
}

int listLength(Node *first)
{
  // works
  int length = 1;
  Node *iterator = first;
  while (iterator->next != NULL)
  {
    iterator = iterator->next;
    ++length;
  }
  return length;
}

Node *getIteratorAtPosition(Node *first, int position)
{
  // works
  int length = listLength(first);
  if (!isInRange(position, 1, length))
    return NULL;
  Node *iterator = first;
  for (int i = 1; i < position; i++)
    iterator = iterator->next;
  return iterator;
}

Node *getEndIterator(Node *first)
{
  // works
  // returns the last node of the list
  Node *iterator = first;
  while (iterator->next != NULL)
    iterator = iterator->next;
  return iterator;
}

Node *insertLast(Node *first, Node *node)
{

  Node *last = getEndIterator(first);
  last->next = node;
  node->previous = last;
  return first;
}
Node *createList()
{

  Node *first = getNode();
  while (getYesNo("Do you want to add another Node? "))
  {
    first = insertLast(first, getNode());
  }
  return first;
}

void printList(Node *first)
{

  Node *iterator = first;
  while (iterator != NULL)
  {
    printNode(iterator);
    iterator = iterator->next;
  }
}

Node *reverse_list(Node *first)
{
  Node *iterator = first;
  while (1)
  {
    Node *temp = iterator->next;
    iterator->next = iterator->previous;
    iterator->previous = temp;
    if (iterator->previous == NULL)
      break;
    iterator = iterator->previous;
  }
  return iterator;
}

#endif
