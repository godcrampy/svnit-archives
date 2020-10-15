#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc == 2){
		int index = isPalindrome(*(argv + 1));
		if (index == 0)
			printf("Not Palindrome!\n");
		else
			printf("Palindrome\n");
	}
	else
		printf("Pass single string command line\n");
	return 0;
}