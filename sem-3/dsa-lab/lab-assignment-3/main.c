#include <stdio.h>
#include "util.h"
#include <string.h>


int main(int argc, char **argv)
{
	Stack s1;
	int capacity = 3;
	s1.top = 0;
	char code;
	do
	{
		printf("Enter Command\n");
		printf("'n' for new book\n");
		printf("'q' for quiting\n");
		printf("'l' for logging stack\n");
		printf("'p' for pop stack\n");
		printf("'s' for peeping into stack\n\n");
		scanf(" %c", &code);
		switch(code)
		{
			case 'n':
			if(s1.top >= capacity)
				printf("Overflow!\n");
			else
			{
				pushBook(getBook(), &s1);
				printf("\nNew Book Added\n");
			}
			break;
			case 'q':
			break;
			case 's':
			printBook(s1.top - 1, &s1);
			break;
			case 'l':
			if(s1.top == 0)
				printf("Empty Stack\n");
			for(int i = s1.top - 1; i >= 0; i--)
				printBook(i, &s1);
			break;
			case 'p':
			printBook(s1.top - 1, &s1);
			popBook(&s1);
			break;
			default:
			printf("Invalid code\n");
		}
	}
	while(code != 'q');
	return 0;
}