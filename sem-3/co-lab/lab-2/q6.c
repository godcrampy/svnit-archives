#include <stdio.h>
#include "util.h"

int main(int argc, char **argv)
{
	if(argc == 3 && is8Bit(*(argv + 1)) && is8Bit(*(argv + 2)))
		doMultiplication(*(argv + 1), *(argv + 2));
	else
		printf("Enter numbers in format: 8bit 8bit\n");
	return 0;
}