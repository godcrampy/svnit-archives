#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		printf("Number of charecters with spaces: %d\n", charecterCountWithSpaces(*(argv + 1)));
		printf("Number of charecters without considering spaces: %d\n", charecterCountWithoutSpaces(*(argv + 1)));
		printf("Word Count: %d\n", wordCount(*(argv + 1)));
	}
	else
		printf("Pass single string via command line\n");
	return 0;
}