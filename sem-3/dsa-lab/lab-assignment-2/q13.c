#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc == 4)
		printf("%s\n", replaceSubstring(*(argv + 1), *(argv + 2), atoi(*(argv + 3))));
	else
		printf("Pass string, substring and index via command line\n");
	return 0;
}