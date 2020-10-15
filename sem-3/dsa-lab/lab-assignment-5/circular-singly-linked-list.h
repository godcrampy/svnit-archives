#ifndef CIRCULAR_SINGLY_LINKED_LIST
#define CIRCULAR_SINGLY_LINKED_LIST 1

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

Node *deleteFirst(Node *first)
{
	int length = listLength(first);
	if (length == 1)
		return NULL;
	Node *last = getEndIterator(first);
	Node *final = first->next;
	last->next = final;
	free(first);
	return final;
}

Node *deleteLast(Node *first)
{

	int length = listLength(first);
	if (length == 1)
		return NULL;
	Node *secondLast = getIteratorAtPosition(first, length - 1);
	free(secondLast->next);
	secondLast->next = first;
	return first;
}

Node *deleteAtIndex(Node *first, int position)
{

	int length = listLength(first);
	if (!isInRange(position, 1, length))
	{
		printf("Position Out of bounds\n");
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
	int length = listLength(first);
	for (int i = 0; i < length; i++)
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
	int length = listLength(first);
	for (int i = 0; i < length; i++)
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
	int length = listLength(first);
	for (int i = 0; i < length; i++)
	{
		if (!strcmp(iterator->name, name))
			return iterator;
		iterator = iterator->next;
	}
	return NULL;
}

#endif