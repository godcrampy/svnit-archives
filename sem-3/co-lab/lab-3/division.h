#ifndef DIVISION
#define DIVISION

#include "util.h"
#include "addition.h"
#include <stdlib.h>

char* shiftLeftA(char* A, char* Q)
{
	char* copy = copyString(A);
	for(int i = 1; i < 8; i++)
		*(copy + i - 1) = *(copy + i);
	*(copy + 7) = *Q;
	return copy;
}

char* shiftLeftQ(char* Q)
{
	char* copy = copyString(Q);
	char temp = '0';
	copy = shiftLeftA(Q, &temp);
	return copy;
}

char* make16Bit(char* binary)
{
	int length = lengthOfString(binary);
	char* final = (char*)malloc(sizeof(char) * 16);
	for(int i = 0; i < 15 - length; i++)
		*(final + i) = 0;
	for(int i = 16 - length; i < 16; i++)
		*(final + i) = *(binary + i - 15);
	return final;
}

void doDivision(char* number1, char* number2)
{
	int sequenceCount = 8;
	char* B = changeBitLength(number2, 8);
	char* temp = changeBitLength(number1, 16);
	char* Q = changeBitLength(temp, 8);
	char *A = newString(8);
	for(int i = 0; i < 8; i++)
		*(A + i) = *(temp + i);
	char E;
	while(sequenceCount > 0)
	{
		E = *A;
		A = shiftLeftA(A, Q);
		Q = shiftLeftQ(Q);

		E = getOverflowBit(A, twosCompliment(B));
		A = addBinary(A, twosCompliment(B));
		if(E == '0')
			A = addBinary(A, B);
		else
			*(Q + 7) = '1';
		sequenceCount--;
	}
	if(*Q == 1)
		Q = twosCompliment(Q);
	if(*A == 1)
		A = twosCompliment(A);
	printf("quotient:%s (%d)\nremainder:%s (%d)\n",Q, binaryToDecimal(Q),A, binaryToDecimal(A));
}

#endif