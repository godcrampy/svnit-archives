#include <stdio.h>
#include "util.h"
#include "addition.h"
#include "booth.h"

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Enter two binary numbers\n");
		return 0;
	}
	if(!isBinary(*(argv + 1)) || !isBinary(*(argv + 2)))
	{
		printf("Enter two binary numbers\n");
		return 0;
	}
	char *bin1 = *(argv + 1);
	char *bin2 = *(argv + 2);
	// if msb is one, convert the number to two's complement
	if (*bin1 == '1')
	{
		*bin1 = '0';
		bin1 = twosCompliment(changeBitLength(bin1, 8));
	}
	else
		bin1 = changeBitLength(bin1, 8);
	if (*bin2 == '1')
	{
		*bin2 = '0';
		bin2 = twosCompliment(changeBitLength(bin2, 8));	
	}
	else
		bin2 = changeBitLength(bin2, 8);
	// do multiplication with numbers in twos complement form
	doMultiplication(bin1, bin2);
	return 0;
}