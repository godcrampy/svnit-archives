#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char** argv)
{
	// WAP to convert decimal to binary
	if(argc == 2 && isInteger(*(argv + 1)))
	{
		long long number = atoll(*(argv + 1));
		if(number < 21)
			printf("%lli\n", factorial(number));
		else
			printf("Integer too large. Try integer below 20\n");
	}
	else
		printf("Pass a decimal number via command line\n");
	return 0;
}

