#include "string.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc == 2)
		printf("%s\n", duplicateConcat(*(argv + 1)));
	else
		printf("Pass a string via command line\n");
	return 0;
}