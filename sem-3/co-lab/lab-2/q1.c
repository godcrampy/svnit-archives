#include "util.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	if(argc == 3)
	{
		if(stringToTypeCode(*(argv + 1)) && isNumberString(*(argv + 2)))
		{
			checkRange(*(argv + 1), *(argv + 2));
			// printRange(*(argv + 1));
		}
		else
			printf("Enter a type and a number via the command line (Example int 45)\n");
	}
	else 
	{
		printf("Enter a type and a number via the command line (Example int 45)\n");
	}
	return 0;
}