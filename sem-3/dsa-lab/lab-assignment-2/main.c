#include <stdio.h>
#include "string.h"
#include <stdlib.h>

int main(int argc, char  **argv)
{
	// Uncomment the program you want to run

	#if 0
	// 1.  Length of string
	if(argc == 2)
		printf("Length of String: %d\n", lengthOfString(*(argv + 1)));
	else
		printf("Pass one input string via command line\n");
	#endif

	#if 0
	// 2. Concatenate two strings
	if(argc == 3)
		printf("%s\n", concatStrings(*(argv + 1), *(argv + 2)));
	else
		printf("Pass two input strings via command line\n");
	#endif

	#if 0
	// 3. Retrieve first index of given symbol
	if(argc == 3)
		if(lengthOfString(*(argv + 2)) == 1)
		{
			int index = firstOccurance(*(argv + 1), **(argv + 2));
			if(index == -1)
				printf("Not Found\n");
			else
				printf("First Occurrance: %d\n", index);
		}
		else
			printf("Enter the second argument as a charecter\n");
	else
		printf("Pass one input string and one charecter via commandline\n");
	#endif

	#if 0
	// 4. Retrieve last index of given symbol
	if(argc == 3)
		if(lengthOfString(*(argv + 2)) == 1)
		{
			int index = lastOccurance(*(argv + 1), **(argv + 2));
			if(index == -1)
				printf("Not Found\n");
			else
				printf("Last Occurrance: %d\n", index);
		}
		else
			printf("Enter the second argument as a charecter\n");
	else
		printf("Pass one input string and one charecter via commandline\n");

	#endif

	#if 0
	// 5. Concatinate the reversal of string
	if(argc == 2)
		printf("%s\n", concatReverse(*(argv + 1)));
	else
		printf("Pass a string via command line\n");
	#endif

	#if 0
	// 6. Duplicate and concatinate main string
	if(argc == 2)
		printf("%s\n", duplicateConcat(*(argv + 1)));
	else
		printf("Pass a string via command line\n");
	#endif

	#if 0
	// 7. Compare Strings
	if(argc == 3)
		printf("%s\n", compareStrings(*(argv + 1), *(argv + 2))?"Equal":"Not Equal");
	else
		printf("Pass two input strings via command line\n");
	#endif

	#if 0
	// 8. Compare strings without case sensitivity
	if(argc == 3)
		printf("%s\n", compareInsensitive(*(argv + 1), *(argv + 2))?"Equal":"Not Equal");
	else
		printf("Pass two input strings via command line\n");
	#endif

	#if 0
	// 9. Reverse string
	if(argc == 2)
		printf("%s\n", reverseString(*(argv + 1)));
	else
		printf("Pass one input string via command line\n");
	#endif

	#if 0
	// 10. Convert string to uppercase
	if(argc == 2)
		printf("%s\n", toUpperCase(*(argv + 1)));
	else
		printf("Pass one input string via command line\n");
	#endif

	#if 0
	// 11. Convert string to lowercase
	if(argc == 2)
		printf("%s\n", toLowerCase(*(argv + 1)));
	else
		printf("Pass one input string via command line\n");
	#endif

	#if 0
	// 12. Convert string to titlecase
	if(argc == 2)
		printf("%s\n", toTitleCase(*(argv + 1)));
	else
		printf("Pass one input string via command line\n");
	#endif

	#if 0
	// 13. Replace the given substring in the main string from the given position
	if(argc == 4)
		printf("%s\n", replaceSubstring(*(argv + 1), *(argv + 2), atoi(*(argv + 3))));
	else
		printf("Pass string, substring and index via command line\n");
	#endif

	#if 0
	// 14. Retrieve the index of the substring in the main string
	if(argc == 3){
		int index = indexOf(*(argv + 1), *(argv + 2));
		if (index == -1)
			printf("Not Found!\n");
		else
			printf("Index: %d\n", index);
	}
	else
		printf("Pass string and substring via command line\n");
	#endif

	#if 0
	// 15. Check the given string is palindrome or not
	if(argc == 2){
		int index = isPalindrome(*(argv + 1));
		if (index == 0)
			printf("Not Palindrome!\n");
		else
			printf("Palindrome\n");
	}
	else
		printf("Pass single string command line\n");
	#endif

	#if 0
	// 16. Display and count the vowels present in the string
	if(argc == 2)
		printf("Number of Vowels: %d\n", countVowels(*(argv + 1)));
	else
		printf("Pass single string via command line\n");
	#endif

	#if 0
	// 17. Count the characters and words
	if(argc == 2)
	{
		printf("Number of charecters with spaces: %d\n", charecterCountWithSpaces(*(argv + 1)));
		printf("Number of charecters without considering spaces: %d\n", charecterCountWithoutSpaces(*(argv + 1)));
		printf("Word Count: %d\n", wordCount(*(argv + 1)));
	}
	else
		printf("Pass single string via command line\n");
	#endif
	return 0;
}