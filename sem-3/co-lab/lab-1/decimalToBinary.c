#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char** argv)
{
	// WAP to convert decimal to binary
	if(argc == 2 && isNumberString(*(argv + 1)))
	{
		float decimal = atof(*(argv + 1));
		printf("%lf\n", decimalToBinary(decimal));
	}
	else
		printf("Pass a decimal number via command line\n");
	return 0;
}
