#include <stdio.h>
#include "util.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	/* code */
	printf("%d\n", power(charToInt(**(argv + 1)), charToInt(**(argv + 2))));
	return 0;
}