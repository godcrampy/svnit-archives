#include "string.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc == 3)
		printf("%s\n", compareStrings(*(argv + 1), *(argv + 2))?"Equal":"Not Equal");
	else
		printf("Pass two input strings via command line\n");
	return 0;
}