#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc == 2)
		printf("Number of Vowels: %d\n", countVowels(*(argv + 1)));
	else
		printf("Pass single string via command line\n");
	return 0;
}