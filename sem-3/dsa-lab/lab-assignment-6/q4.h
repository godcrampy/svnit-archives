#include <stdlib.h>
#include <stdio.h>

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
  printf("'s' for Split\n");
  printf("'p' for Print\n");
  printf("'q' for Quitting\n");
  char c = 'a';
  while (1)
  {
    printf("Enter Command: ");
    scanf(" %c", &c);
    getchar(); // To clean the buffer
    if (c == 's' || c == 'S')
      return 's';
    if (c == 'p' || c == 'P')
      return 'p';
    if (c == 'q' || c == 'Q')
      return 'q';
  }
}

typedef struct node
{
  int data;
  struct node *next;
} Node;

Node *getNode()
{
  // works
  // gets the data from the user and returns a node pointer
  Node *final = (Node *)malloc(sizeof(Node));
  printf("Enter Data: ");
  scanf("%d", &final->data);
  getchar(); // To clean the buffer
  final->next = NULL;
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
  int length = 1;
  Node *iterator = first;
  while (iterator->next != first)
  {
    iterator = iterator->next;
    ++length;
  }
  return length;
}

Node *getIteratorAtPosition(Node *first, int position)
{
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

  // returns the last node of the list
  Node *iterator = first;
  while (iterator->next != first)
    iterator = iterator->next;
  return iterator;
}

Node *insertFirst(Node *first, Node *node)
{
  Node *last = getEndIterator(first);
  last->next = node;
  node->next = first;
  return node;
}

Node *insertLast(Node *first, Node *node)
{

  Node *last = getEndIterator(first);
  last->next = node;
  node->next = first;
  return first;
}

Node *insertAtIndex(Node *first, Node *node, int position)
{

  int length = listLength(first);
  if (!isInRange(position, 0, length + 1))
  {
    printf("Position Out Of Bounds\n");
    return first;
  }
  if (position == 1 || position == 0)
    return insertFirst(first, node);
  if (position == length + 1)
    return insertLast(first, node);
  Node *iterator = getIteratorAtPosition(first, position - 1);
  node->next = iterator->next;
  iterator->next = node;
  return first;
}

Node *createList()
{

  Node *first = getNode();
  first->next = first;
  while (getYesNo("Do you want to add another Node? "))
  {
    first = insertLast(first, getNode());
  }
  return first;
}

void printList(Node *first)
{

  Node *iterator = first;
  printNode(iterator);
  iterator = iterator->next;
  while (iterator != first)
  {
    printNode(iterator);
    iterator = iterator->next;
  }
}

Node **split_list(Node *first, Node **a)
{
  Node *fast_iterator = first;
  Node *slow_iterator = first;
  do
  {
    fast_iterator = fast_iterator->next->next;
    slow_iterator = slow_iterator->next;
  } while (!(fast_iterator == first || fast_iterator == first->next));
  Node *new_first = slow_iterator->next;
  slow_iterator->next = fast_iterator->next;
  fast_iterator->next = new_first;
  a[0] = slow_iterator;
  a[1] = fast_iterator;
}