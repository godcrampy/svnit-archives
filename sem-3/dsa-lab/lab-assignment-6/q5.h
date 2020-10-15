#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_STRING_LENGTH 50

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
  printf("'n' for New URL\n");
  printf("'b' for Back\n");
  printf("'f' for Forward\n");
  printf("'h' for History\n");
  printf("'q' for Quit\n");
  char c = 'a';
  while (1)
  {
    printf("Enter Command: ");
    scanf(" %c", &c);
    getchar(); // To clean the buffer
    if (c == 'n' || c == 'n')
      return 'n';
    if (c == 'b' || c == 'B')
      return 'b';
    if (c == 'f' || c == 'F')
      return 'f';
    if (c == 'h' || c == 'H')
      return 'h';
    if (c == 'q' || c == 'Q')
      return 'q';
  }
}

typedef struct node
{
  char URL[MAX_STRING_LENGTH];
  struct node *previous;
  struct node *next;
} Node;

Node *getNode()
{

  // gets the data from the user and returns a node pointer
  Node *final = (Node *)malloc(sizeof(Node));
  printf("Enter URL: ");
  fgets(final->URL, MAX_STRING_LENGTH, stdin);
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
    printf("%s", node->URL);
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

void printList(Node *first)
{

  Node *iterator = first;
  while (iterator != NULL)
  {
    printNode(iterator);
    iterator = iterator->next;
  }
}

Node *deleteFirst(Node *first)
{
  int length = listLength(first);
  if (length == 1)
  {
    free(first);
    return NULL;
  }
  Node *final = first->next;
  final->previous = NULL;
  free(first);
  return final;
}
