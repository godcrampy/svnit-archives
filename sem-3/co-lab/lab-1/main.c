#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char** argv)
{
	// Uncomment the program you want to run

	#if 0
	// Program 1
	// WAP to convert binary to decimal

	if(argc == 2 && isBinary(*(argv + 1)))
	{
		float binary = atof(*(argv + 1));
		printf("%lf\n", binaryToDecimal(binary));
	}
	else
		printf("Pass a binary number via command line\n");

	#endif
	
	#if 0
	// Program 2
	// WAP to convert decimal to binary

	if(argc == 2 && isNumberString(*(argv + 1)))
	{
		float decimal = atof(*(argv + 1));
		printf("%lf\n", decimalToBinary(decimal));
	}
	else
		printf("Pass a decimal number via command line\n");

	#endif

	#if 0
	// Program 3
	// WAP for recursive factorial

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
	#endif
	

	return 0;
}