#include <stdio.h>
#include "util.h"

int main(int argc, char **argv)
{
	printf("%d\n", isBinary(*(argv + 1)));
	return 0;
}