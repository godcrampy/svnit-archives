#ifndef UTIL
#define UTIL

#include <stdio.h>
#include <string.h>

typedef struct book
{
	float price;
	char id[20];
	char name[50];
}Book;

typedef struct stack
{
	Book array[3];
	int top;
}Stack;

void printBook(int position, Stack* s1)
{
	// prints the book data in formatted form
	printf("============\n");
	printf("Id: %sName: %sPrice: %0.3f\n", s1->array[position].id, s1->array[position].name, s1->array[position].price);
	printf("============\n");
}



Book getBook()
{
	// scans the date from the user and returns the book structure
	Book newBook;
	newBook.id[0] = 10;
	newBook.name[0] = 10;
	char temp[10];
	fgets(temp, 10, stdin);
	float price = -1;
	while(newBook.name[0] == 10)
	{
		printf("Enter Book Name: ");
		fgets(newBook.name, 50, stdin);
	}
	while(newBook.id[0] == 10){
		printf("Enter Book Id: ");
		fgets(newBook.id, 20, stdin);
	}
	while(price <= 0)
	{
		printf("Enter Book Price: ");
		scanf("%f", &price);
	}
	newBook.price = price;
	return newBook;
}

void pushBook(Book book, Stack* s1)
{
	// pushes a new book
	strcpy(s1->array[s1->top].name, book.name);
	strcpy(s1->array[s1->top].id, book.id);
	s1->array[s1->top].price = book.price;
	s1->top += 1;
}

void popBook(Stack* s1)
{
	if(s1->top == 0)
		printf("Empty Stack\n");
	else
	{
		s1->top -= 1;
		printf("Book Popped\n");
	}
}
#endif
