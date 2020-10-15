#include "string.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc == 3)
		if(lengthOfString(*(argv + 2)) == 1)
		{
			int index = lastOccurance(*(argv + 1), **(argv + 2));
			if(index == -1)
				printf("Not Found\n");
			else
				printf("Last Occurrance: %d\n", index);
		}

		else
			printf("Enter the second argument as a charecter\n");
	else
		printf("Pass one input string and one charecter via commandline\n");
	return 0;
}