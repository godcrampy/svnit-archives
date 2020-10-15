#include <stdio.h>
#include "booth.h"
#include "util.h"
#include "addition.h"
#include "division.h"

int main(int argc, char **argv)
{
	doDivision(*(argv + 1), *(argv + 2));
	return 0;
}