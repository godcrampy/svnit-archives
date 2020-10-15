#ifndef ADDITION
#define ADDITION

#include "util.h"
#include <stdlib.h>

char fullAdd(char a, char b, char c)
{
	// works
	int x = charToBinary(a), y = charToBinary(b), z = charToBinary(c);
	return binaryToChar(x ^ y ^ z);
}

char getCarry(char a, char b, char c)
{
	// works
	int x = charToBinary(a), y = charToBinary(b), z = charToBinary(c);
	return binaryToChar(((x & y) | (z & (x ^ y))));
}

char getOverflowBit(char* number1, char* number2)
{
	// works
	// returns the overflow bit of addBinary function
	int length = max(lengthOfString(number1), lengthOfString(number2));
	char* binary1 = changeBitLength(number1, length);
	char* binary2 = changeBitLength(number2, length);
	char* carry = newString(length + 1);
	char* solution = newString(length);
	for(int i = length - 1; i >= 0; i--)
	{
		*(solution + i) = fullAdd(*(binary1 + i), *(binary2 + i), *(carry + i + 1));
		*(carry + i) = getCarry(*(binary1 + i), *(binary2 + i), *(carry + i + 1));
	}
	return *carry;
}

char* add8BitNumbers(char* number1, char* number2)
{
	// works
	char carry[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};
	char* solution = (char*)malloc(sizeof(char) * 8);
	for(int i = 7; i >= 0; i--)
	{
		*(solution + i) = fullAdd(*(number1 + i), *(number2 + i), *(carry + i + 1));
		*(carry + i) = getCarry(*(number1 + i), *(number2 + i), *(carry + i + 1));
	}
	return solution;
}

char* addBinary(char* number1, char* number2)
{
	// works
	// add two binary numbers by returning a binary number
	// of length the max of the two numbers 
	int length = max(lengthOfString(number1), lengthOfString(number2));
	char* binary1 = changeBitLength(number1, length);
	char* binary2 = changeBitLength(number2, length);
	char* carry = newString(length + 1);
	char* solution = newString(length);
	for(int i = length - 1; i >= 0; i--)
	{
		*(solution + i) = fullAdd(*(binary1 + i), *(binary2 + i), *(carry + i + 1));
		*(carry + i) = getCarry(*(binary1 + i), *(binary2 + i), *(carry + i + 1));
	}
	return solution;
}

char* onesCompliment(char* binary)
{
	// works
	int length = lengthOfString(binary);
	char* final = copyString(binary);
	for(int i = 0; i < length; i++)
		*(final + i) = NOT(*(binary + i));
	return final;
}

char* twosCompliment(char* binary)
{
	// works
	int length = lengthOfString(binary);
	char* final = copyString(binary);
	final = onesCompliment(final);
	for(int i = length - 1; i >= 0; i--)
	{
		*(final + i) = NOT(*(final + i));
		if(*(final + i) == '1')
			break;
	}
	return final;
}

#endif