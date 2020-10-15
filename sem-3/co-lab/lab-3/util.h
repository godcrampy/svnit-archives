#ifndef UTIL
#define UTIL

#include <stdlib.h>

int lengthOfString(char* string)
{
	// works
	// returns the length of string
	int counter = 0;
	while(*(string + counter) != '\0')
		counter++;
	return counter;
}

char* newString(int size)
{
	// works
	// Returns a string of given length all charecters '0'
	char* final = (char*)malloc(sizeof(char) * size);
	for(int i = 0; i < size; i++)
		*(final + i) = '0';
	return final;
}

char* copyString(char* string)
{
	// works
	// returns a copy of the given string
	int length = lengthOfString(string);
	char* final = newString(length);
	for(int i = 0; i < length; i++)
		*(final + i) = *(string + i);
	return final;
}

char* concatStrings(char* stringA, char* stringB)
{
	// works
	// returns the concat of the given strings
	int finalLength = lengthOfString(stringA) + lengthOfString(stringB),
	firstLength = lengthOfString(stringA);
	char* final = (char*)malloc(sizeof(char) * (finalLength));
	for(int i = 0; i < finalLength; i++)
		*(final + i) = i < firstLength ? *(stringA + i) : *(stringB + i - firstLength);
	return final;
}

char* rightShift(char* string)
{
	// works
	// returns the right shift of the given string
	int length = lengthOfString(string);
	char* final = copyString(string);
	for(int i = length - 1; i >= 1; i--)
		*(final + i) = *(string + i - 1);
	*final = '0';
	return final;
}

char* arithmeticRightShift(char* string)
{
	// works
	// returns the arithmetic right shift of the given string
	char* final = rightShift(string);
	*final = '1';
	return final;
}

int isBinary(char* string)
{
	// works
	int length = lengthOfString(string);
	for(int i = 0; i < length; i++)
	{
		if(*(string + i) != '0' && *(string + i) != '1')
			return 0;
	}
	return 1;
}

int is8BitBinary(char* string)
{
	// works
	return isBinary(string) && lengthOfString(string) == 8 ? 1 : 0;
}

int charToBinary(char c)
{
	// works
	return c == '0' ? 0 : 1;
}

char binaryToChar(int b)
{
	// works
	return b == 0 ? '0' : '1';
}

char NOT(char a)
{
	// works
	return a == '0' ? '1' : '0';
}

int binaryToDecimal(char* binary)
{
	// works
	int length = lengthOfString(binary), decimal = 0;
	for(int i = 0; i < length; i++){
		if(*(binary + i) != '0')
			decimal += 1 << (length - i - 1);
	}
	return decimal;
}

char* changeBitLength(char* binary, int size)
{
	// works
	// chages the length of the given binary string. Use to increase string length
	int length = lengthOfString(binary);
	if(size == length)
		return binary;
	char* final = newString(size);
	for(int i = size - length; i < size; i++)
		*(final + i) = *(binary + i - size + length);
	return final;
}

int max(int a, int b)
{
	// works
	return a > b ? a : b;
}

#endif