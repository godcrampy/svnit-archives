#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char **argv)
{
	printf("%s\n", _decimalToBinary(atoi(*(argv + 1))));
	return 0;
}