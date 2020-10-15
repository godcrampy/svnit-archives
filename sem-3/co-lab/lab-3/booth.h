#ifndef BOOTH
#define BOOTH

#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "addition.h"

char* arithmeticShiftRightLongAc(char *ac)
{
	char *copy;
	copy = copyString(ac);
	for(int i = 1; i < 8; i++)
		*(ac + i) = *(copy+ i-1);
	return ac;
}

char* arithmeticShiftRightLongQr(char *qr)
{
	char *copy;
	copy = copyString(qr);
	for(int i = 1; i < 8; i++)
		*(qr + i) = *(copy + i-1);
	return qr;
}

char* display(char *aC , char *qR , char sign1 , char sign2)
{
	if(sign1 ^ sign2)
	{
		char *res;
		res = concatStrings(aC,qR);
		*res = '0';
		return twosCompliment(res);
	}
	return concatStrings(aC, qR);
}

void doMultiplication(char* bR, char* qR)
{
	int sequenceCount = 8;
	char Qnp1 = '0', sign1 = *bR, sign2 = *qR;
	char* aC = newString(8);
	while(sequenceCount > 0)
	{
		if(*(qR + 7) == '1' && Qnp1 == '0')
			aC = addBinary(aC, twosCompliment(bR));
		if(*(qR + 7) == '0' && Qnp1 == '1')
			aC = addBinary(aC, bR);
		char temp = *(qR+7) , tempN = *(aC+7);
		Qnp1 = temp;
		aC = arithmeticShiftRightLongAc(aC);
		qR = arithmeticShiftRightLongQr(qR);
		*(qR+0) = tempN;
		sequenceCount--;
	}

	// if (sign1^sign2)
		// printf("%s  (-%d)\n", display(aC, qR, sign1, sign2),binaryToDecimal(display(aC, qR, sign1, sign2)));
	// else 
		// printf("%s  (+%d)\n", display(aC, qR, sign1, sign2),binaryToDecimal(display(aC, qR, sign1, sign2)));
	// if(sign1^sign2)
		// printf("%s (-%d)\n", concatStrings(aC, qR), binaryToDecimal(concatStrings(aC, qR)));
	// else
		// printf("%s (%d)\n", concatStrings(aC, qR), binaryToDecimal(concatStrings(aC, qR)));
	char* result = concatStrings(aC, qR);
	if(*result == '1')
		printf("%s (-%d)\n", result, binaryToDecimal(twosCompliment(result)));
	else
		printf("%s (%d)\n", result, binaryToDecimal(result));
}

#endif