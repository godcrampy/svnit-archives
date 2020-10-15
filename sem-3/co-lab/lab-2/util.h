#ifndef UTIL
#define UTIL

#include <stdlib.h>
#include <stdio.h>

//=== Question 1 Utils ===//
int lengthOfString(char* string)
{
	int i = 0;
	while(*(string + i) != '\0')
		i++;
	return i;
}

int _isInRange(long long left, long long right,long long testNumber)
{
	return testNumber >= left && testNumber <= right ? 1 : 0;
}

int _isNumber(char number)
{
	return _isInRange(48, 57, number);
}

int isNumberString(char* string)
{
	if(*(string) != '-' && !_isNumber(*(string)))
		return 0;
	for(int i = 1; i < lengthOfString(string); i++)
		if(!_isNumber(*(string + i)))
			return 0;
	return 1;
}

int _compareStrings(char* stringA, char* stringB)
{
	int length1 = lengthOfString(stringA), length2 = lengthOfString(stringB);
	if(length1 != length2)
		return 0;
	for(int i = 0; i <length1; i++)
		if(*(stringA + i) != *(stringB + i))
			return 0;
	return 1;
}

int stringToTypeCode(char* string)
{
	if(_compareStrings(string, "char"))
		return 1;
	if(_compareStrings(string, "int"))
		return 2;
	if(_compareStrings(string, "long"))
		return 3;
	if(_compareStrings(string, "float"))
		return 4;
	return 0;
}

void checkRange(char* type, char* numberString)
{
	long long number = atoll(numberString);
	int typeCode = stringToTypeCode(type);
	switch(typeCode)
	{
		case 1:
		// char
		printf("%s\n", _isInRange(-127, 127, number) ? "In range" : "Not in range");
		printf("Range: [%d, %d]\n", -127, 127);
		break;
		case 2:
		// int
		printf("%s\n", _isInRange(-32767, 32767, number) ? "In range" : "Not in range");
		printf("Range: [%d, %d]\n", -32767, 32767);
		break;
		case 3:
		case 4:
		// long
		//float
		printf("%s\n", _isInRange(-2147483647, 2147483647, number) ? "In range" : "Not in range");
		printf("Range: [-2147483647, 2147483647]\n");
		break;
		default:
		printf("Invalid type string\n");
	}
}
//=== Question 2 Utils ===//
int getOpcode(char* string)
{
	if( lengthOfString(string) != 1)
		return 0;
	switch(*(string))
	{
		case '+':
			return 1;
		case '-':
			return 2;
		case 'x':
			return 3;
		case '/':
			return 4;
		default:
			return 0;
	}
}

//=== Question 5 Utils ===//
int _isBit(char charecter)
{
	return charecter == '1' || charecter == '0' ? 1 : 0;
}
int is8Bit(char* binary)
{
	if(lengthOfString(binary) != 8)
		return 0;
	for(int i = 0; i < 8; i++)
		if(!_isBit(*(binary + i)))
			return 0;
	return 1;
}

int isPlusMinus(char* operation)
{
	if(lengthOfString(operation) != 1)
		return 0;
	if(*(operation) == '+' || *(operation) == '-')
		return 1;
	return 0;
}

char _NOT(char bit)
{
	return bit == '1' ? '0' : '1';
}

char* _onesCompliment(char* binary)
{
	for(int i = 0; i < lengthOfString(binary); i++)
		*(binary + i) = _NOT(*(binary + i));
	return binary;
}

char* _twosCompliment(char* binary)
{
	binary = _onesCompliment(binary);
	for(int i = 7; i >= 0; i--)
	{
		*(binary + i) = _NOT(*(binary + i));
		if(*(binary + i) == '1')
			break;
	}
	return binary;
}

int _binaryToDecimal(char* binary)
{
	int negativeFlag = 1, decimal = 0;
	if(*(binary) == '1')
	{
		binary = _twosCompliment(binary);
		negativeFlag = -1;
	}
	for(int i = 0; i < 8; i++)
		decimal += *(binary + i) == '1' ? 1 << (7 - i) : 0;
	return negativeFlag == 1 ? decimal : -1 * decimal;

}

char* _decimalToBinary(int decimal)
{
	int tensPlace = 1;
	long binary = 0;
	// Convert integer part
	while (decimal != 0)
	{
		int remainder = decimal % 2;
		binary += tensPlace * remainder;
		decimal /= 2;
		tensPlace *= 10;
	}
	binary += 10000000;
	char* binaryString = (char*)malloc(sizeof(char) * 9);
	sprintf(binaryString, "%li", binary);
	*(binaryString) = '0';
	return binaryString;
}

void doAddition(char* binaryA,char* binaryB)
{
	int a = _binaryToDecimal(binaryA), b = _binaryToDecimal(binaryB);
	int result = a + b;
	if(!_isInRange(-128, 127, result))
		printf("Overflow!\n");
	else
		if(result < 0)
			printf("%s (%d)\n", _twosCompliment(_decimalToBinary(result * -1)), result);
		else
			printf("%s (%d)\n", _decimalToBinary(result), result);
}

void doSubtraction(char* binaryA,char* binaryB)
{
	int a = _binaryToDecimal(binaryA), b = _binaryToDecimal(binaryB);
	int result = a - b;
	if(!_isInRange(-128, 127, result))
		printf("Overflow!\n");
	else
		if(result < 0)
			printf("%s (%d)\n", _twosCompliment(_decimalToBinary(result * -1)), result);
		else
			printf("%s (%d)\n", _decimalToBinary(result), result);
}
// === Question 6 Utils ===//
int _binaryToDecimalUnsigned(char* binary)
{
	int decimal = 0;
	for(int i = 0; i < 8; i++)
		decimal += *(binary + i) == '1' ? 1 << (7 - i) : 0;
	return decimal;
}

char* _decimalToBinaryUnsigned(int decimal)
{
	int tensPlace = 1;
	long binary = 0;
	// Convert integer part
	while (decimal != 0)
	{
		int remainder = decimal % 2;
		binary += tensPlace * remainder;
		decimal /= 2;
		tensPlace *= 10;
	}
	if (decimal < 128)
		binary += 10000000;
	char* binaryString = (char*)malloc(sizeof(char) * 9);
	sprintf(binaryString, "%li", binary);
	if (decimal < 128)
		*(binaryString) = '0';
	return binaryString;
}

void doMultiplication(char* binaryA,char* binaryB)
{
	int a = _binaryToDecimalUnsigned(binaryA), b = _binaryToDecimalUnsigned(binaryB);
	int result = a * b;
	if(!_isInRange(-128, 127, result))
		printf("Overflow!\n");
	else
		printf("%s (%d)\n", _decimalToBinaryUnsigned(result), result);
}
#endif