#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char** argv)
{
	// WAP to convert decimal to binary
	if(argc == 2 && isBinary(*(argv + 1)))
	{
		float binary = atof(*(argv + 1));
		printf("%lf\n", binaryToDecimal(binary));
	}
	else
		printf("Pass a binary number via command line\n");
	return 0;
}

