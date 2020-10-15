#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc == 3){
		int index = indexOf(*(argv + 1), *(argv + 2));
		if (index == -1)
			printf("Not Found!\n");
		else
			printf("Index: %d\n", index);
	}
	else
		printf("Pass string and substring via command line\n");
	return 0;
}