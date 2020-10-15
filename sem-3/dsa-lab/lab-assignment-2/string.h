#ifndef STRING
#define STRING

#include <stdlib.h>
#include <stdio.h>

int lengthOfString(char* string)
{
	int i = 0;
	while(*(string + i) != '\0')
		i++;
	return i;
}

char* concatStrings(char* stringA, char* stringB)
{
	int finalLength = lengthOfString(stringA) + lengthOfString(stringB),
	firstLength = lengthOfString(stringA);
	char* final = (char*)malloc(sizeof(char) * (finalLength + 1));
	for(int i = 0; i < finalLength; i++)
		*(final + i) = i < firstLength ? *(stringA + i) : *(stringB + i - firstLength);
	return final;
}

int firstOccurance(char* string, char charecter)
{
	for(int i = 0; i < lengthOfString(string); i++)
		if(*(string + i) == charecter)
			return ++i;
	return -1;
}

int lastOccurance(char* string, char charecter)
{
	for(int i = lengthOfString(string) - 1; i >= 0; i--)
		if(*(string + i) == charecter)
			return ++i;
	return -1;
}

char* reverseString(char* string)
{
	char* reverse = (char*)malloc(lengthOfString(string) + 1);
	int length = lengthOfString(string);
	for(int i = 0; i < length; i++)
		*(reverse + length - i - 1) = *(string + i);
	return reverse;
}

char* concatReverse(char* string)
{
	return concatStrings(string, reverseString(string));
}

char* duplicateConcat(char* string)
{
	return concatStrings(string, string);
}

int compareStrings(char* stringA, char* stringB)
{
	int length1 = lengthOfString(stringA), length2 = lengthOfString(stringB);
	if(length1 != length2)
		return 0;
	for(int i = 0; i <length1; i++)
		if(*(stringA + i) != *(stringB + i))
			return 0;
	return 1;
}

char _toUpper(char a)
{
	return a > 96 && a < 123 ? a - 32 : a;
}


char _toLower(char a)
{
	return a > 64 && a < 91 ? a + 32 : a;
}

void _copyString(char* stringA, char* stringB)
{
	for(int i = 0; i < lengthOfString(stringA); i++)
		*(stringB + i) = *(stringA + i);
}

int compareInsensitive(char* stringA, char* stringB)
{
	int length1 = lengthOfString(stringA);
	int length2 = lengthOfString(stringB);
	char* stringAInsensitive = (char*)malloc(sizeof(char) * (length1 + 1));
	char* stringBInsensitive = (char*)malloc(sizeof(char) * (length2 + 2));
	_copyString(stringA, stringAInsensitive);
	_copyString(stringB, stringBInsensitive);
	for(int i = 0; i < length1; i++)
		*(stringAInsensitive + i) = _toLower(*(stringA + i));
	for(int i = 0; i < length2; i++)
		*(stringBInsensitive + i) = _toLower(*(stringB + i));
	return compareStrings(stringAInsensitive, stringBInsensitive);
}

char* toUpperCase(char* string)
{
	char* final = (char*)malloc(sizeof(char)*(lengthOfString(string) + 1));
	for(int i = 0; i < lengthOfString(string); i++)
		 *(final + i) = _toUpper(*(string + i));
	return final;
}
char* toLowerCase(char* string)
{
	char* final = (char*)malloc(sizeof(char)*(lengthOfString(string) + 1));
	for(int i = 0; i < lengthOfString(string); i++)
		 *(final + i) = _toLower(*(string + i));
	return final;
}

char* toTitleCase(char* string)
{
	int length = lengthOfString(string);
	char* final = (char*)malloc(sizeof(char)*(length));
	_copyString(string, final);
	if(length == 0)
		return final;
	*(final) = _toUpper(*(final));
	for(int i = 0; i < length - 1; i++)
		if((int)*(final + i) == 32)
			*(final + i + 1) = _toUpper(*(final + i + 1));
	return final;
}

int isPalindrome(char* string)
{
	int length = lengthOfString(string);
	char* reverse = (char*)malloc(sizeof(char)*(length + 1));
	return compareStrings(string, reverseString(string));
}

int _isVowel(char charecter)
{
	switch(charecter)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		return 1;
		break;
		default:
		return 0;
	}
}

int countVowels(char* string)
{
	int count = 0;
	string = toLowerCase(string);
	for(int i = 0; i < lengthOfString(string); i++)
		if(_isVowel(*(string + i)))
			count++;
	return count;
}

int _max(int a, int b)
{
	return a > b ? a : b;
}

int _mod(int a)
{
	return a > 0 ? a : -1 * a;
}

char* replaceSubstring(char* string, char* subString, int index)
{
	int stringLength = lengthOfString(string);
	int subStringLength = lengthOfString(subString);
	int length = _max(stringLength, _mod(index) + subStringLength);
	char* final = (char*)malloc(sizeof(char) * length);
	if(index > stringLength || index + subStringLength < 0)
		return "Index beyond Range";
	if (index < 0)
	{
		_copyString(subString, final);
		_copyString(string + subStringLength + index, final + subStringLength);
		return final;
	}
	_copyString(string, final);
	_copyString(subString, final + index);
	return final;
}

int indexOf(char* string, char* subString)
{
	int length = lengthOfString(string), index = 0;
	int subStringLength = lengthOfString(subString);
	for(int i = 0; i < length; i++)
	{
		int foundFlag = 1;
		for(int j = 0; j < subStringLength; j++)
			if(*(string + i + j) != *(subString + j))
			{
				foundFlag = 0;
				break;
			}
		if(foundFlag)
			return i;
	}
	return -1;
}
int _spacesCount(char* string)
{
	int count = 0;
	for(int i = 0; i < lengthOfString(string); i++)
		if(*(string + i) == 32)
			count++;
	return count;
}

int charecterCountWithSpaces(char* string)
{
	return lengthOfString(string);
}

int charecterCountWithoutSpaces(char* string)
{
	return lengthOfString(string) - _spacesCount(string);
}

int _firstValidCharIndex(char* string)
{
	for(int i = 0; i < lengthOfString(string); i++)
		if(*(string + i) != 32)
			return i;
}

int wordCount(char* string)
{
	int count = 1;
	for(int i = _firstValidCharIndex(string) + 1; i < lengthOfString(string); i++)
		if(*(string + i) != 32 && *(string + i - 1) == 32)
			count++;
	return count;
}
#endif