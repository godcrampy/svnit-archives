#ifndef LINEAR_SINGLY_LINKED_LIST
#define LINEAR_SINGLY_LINKED_LIST 1

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#define MAX_STRING_LENGTH 50

// ASSUMPTION: 1 Index Linked List

typedef struct node
{
	int rollNumber;
	float cgpa;
	char name[MAX_STRING_LENGTH];
	struct node *next;
} Node;

Node *getNode()
{
	// works
	// gets the data from the user and returns a node pointer
	Node *final = (Node *)malloc(sizeof(Node));
	printf("Enter Name: ");
	fgets(final->name, MAX_STRING_LENGTH, stdin);
	printf("Enter Roll Number: ");
	scanf("%d", &final->rollNumber);
	getchar(); // To clean the buffer
	printf("Enter CGPA: ");
	scanf("%f", &final->cgpa);
	getchar(); // To clean th buffer
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
		printf("Name: %s", node->name);
		printf("Roll Number: %d\n", node->rollNumber);
		printf("CGPA: %0.2f\n", node->cgpa);
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

int doesRollNumberExist(Node *first, int rollNumber)
{
	Node *iterator = first;
	while (iterator != NULL)
	{
		if (iterator->rollNumber == rollNumber)
			return 1;
		iterator = iterator->next;
	}
	return 0;
}

Node *insertFirst(Node *first, Node *node)
{
	// works
	node->next = first;
	return node;
}

Node *insertLast(Node *first, Node *node)
{
	// works
	Node *last = getEndIterator(first);
	last->next = node;
	return first;
}

Node *insertAtIndex(Node *first, Node *node, int position)
{
	// works
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

Node *insertSorted(Node *first, Node *node)
{
	Node *iterator = first;
	int iteratorIndex = 1;
	Node *last = getEndIterator(first);
	if (node->rollNumber < first->rollNumber)
		return insertFirst(first, node);
	if (node->rollNumber > last->rollNumber)
		return insertLast(first, node);
	while (iterator->next != last)
	{
		if (node->rollNumber > iterator->rollNumber && node->rollNumber < iterator->next->rollNumber)
			return insertAtIndex(first, node, iteratorIndex + 1);
		iterator = iterator->next;
		iteratorIndex++;
	}
	return insertAtIndex(first, node, iteratorIndex + 1);
}

Node *createList()
{
	// works
	Node *first = getNode();
	while (getYesNo("Do you want to add another Node? "))
	{
		Node *node = getNode();
		if (doesRollNumberExist(first, node->rollNumber))
			printf("Conflict: Roll Number Already Exists\n");
		else
			first = insertSorted(first, node);
	}
	return first;
}

void printList(Node *first)
{
	// works
	Node *iterator = first;
	while (iterator != NULL)
	{
		printNode(iterator);
		iterator = iterator->next;
	}
}

Node *deleteFirst(Node *first)
{
	// works
	Node *final = first->next;
	free(first);
	return final;
}

Node *deleteLast(Node *first)
{
	// works
	int length = listLength(first);
	if (length == 1)
	{
		free(first);
		return NULL;
	}
	Node *secondLast = getIteratorAtPosition(first, length - 1);
	free(secondLast->next);
	secondLast->next = NULL;
	return first;
}

Node *deleteAtIndex(Node *first, int position)
{
	// works
	int length = listLength(first);
	if (!isInRange(position, 1, length))
	{
		printf("Position Out of bounds");
		return first;
	}
	if (position == 1)
		return deleteFirst(first);
	if (position == length)
		return deleteLast(first);
	Node *iterator = getIteratorAtPosition(first, position - 1);
	Node *trash = iterator->next;
	iterator->next = iterator->next->next;
	free(trash);
	return first;
}

Node *searchRollNumber(Node *first, int rollNumber)
{
	Node *iterator = first;
	while (iterator != NULL)
	{
		if (iterator->rollNumber == rollNumber)
			return iterator;
		iterator = iterator->next;
	}
	return NULL;
}

Node *searchCGPA(Node *first, float cgpa)
{
	Node *iterator = first;
	while (iterator != NULL)
	{
		if (iterator->cgpa == cgpa)
			return iterator;
		iterator = iterator->next;
	}
	return NULL;
}

Node *searchName(Node *first, char *name)
{
	Node *iterator = first;
	while (iterator != NULL)
	{
		if (!strcmp(iterator->name, name))
			return iterator;
		iterator = iterator->next;
	}
	return NULL;
}

#endif