#ifndef UTIL
#define UTIL

#include <stdlib.h>

int _lengthOfString(char* string)
{
	int i = 0;
	while(*(string + i) != '\0')
		i++;
	return i;
}

double decimalToBinary(float decimal)
{
	int prePoint = decimal;
	double postPoint = decimal - prePoint, binary;
	double tensPlace = 1;

	// Convert integer part
	while (prePoint != 0)
	{
		int remainder = prePoint % 2;
		binary += tensPlace * remainder;
		prePoint /= 2;
		tensPlace *= 10;
	}

	// Convert points part
	tensPlace = 0.1;
	while (postPoint >= 0.00001)
	{
		double remainder = (int)(postPoint * 2);
		binary += remainder * tensPlace;
		postPoint = postPoint * 2 - remainder;
		tensPlace /= 10;
	}
	return binary;
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
	for(int i = 1; i < _lengthOfString(string); i++)
		if(!_isNumber(*(string + i)))
			return 0;
	return 1;
}

int isInteger(char* string)
{
	if(!isNumberString(string))
		return 0;
	for(int i = 0; i < _lengthOfString(string); i++)
		if(*(string + i) == '.')
			return 0;
	return 1;
}

int isBinary(char* string)
{
	if(!isNumberString(string))
		return 0;
	short pointFlag = 0;
	for(int i = 0; i < _lengthOfString(string); i++)
	{
		if(*(string + i) == '.')
		{
			if(pointFlag)
				return 0;
			pointFlag = 1;
		}
		if(*(string + i) != '1' && *(string + i) != '0' && *(string + i) != '.')
			return 0;
	}
	return 1;
}

double binaryToDecimal(float binary)
{
	int prePoint = binary;
	double postPoint = binary - prePoint, decimal = 0;
	double tensPlace = 1;

	// Convert integer part
	while (prePoint != 0)
	{
		int remainder = prePoint % 10;
		decimal += tensPlace * remainder;
		prePoint /= 10;
		tensPlace *= 2;
	}
	// Convert points part
	tensPlace = 0.5;
	while (postPoint > 0.0001)
	{
		int remainder = postPoint * 10;
		if (remainder >= 1)
			decimal += tensPlace;
		postPoint = postPoint * 10 - remainder;
		tensPlace /= 2;
	}
	return decimal;
}

long long factorial(long number)
{
	return number == 1 ? 1 : number * factorial(number - 1);	
}

#endif
