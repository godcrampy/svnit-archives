#include "string.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc == 2)
		printf("Length of String: %d\n", lengthOfString(*(argv + 1)));
	else
		printf("Pass one input string via command line\n");
	return 0;
}