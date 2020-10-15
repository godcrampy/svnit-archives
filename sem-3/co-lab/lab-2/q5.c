#include <stdio.h>
#include "util.h"

int main(int argc, char **argv)
{
	if(argc == 4 && is8Bit(*(argv + 1)) && isPlusMinus(*(argv + 2)) && is8Bit(*(argv + 3)))
		**(argv + 2) == '+' ? doAddition(*(argv + 1), *(argv + 3)) : doSubtraction(*(argv + 1), *(argv + 3));
	else
		printf("Enter numbers in format: 8bit +/- 8bit\n");
	return 0;
}