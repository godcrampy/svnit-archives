#include <stdlib.h>
#include <stdio.h>
#include "util.h"

int main(int argc, char **argv)
{
	// Uncomment the program you want to run
	#if 0
	// Question 1: Check range of given type

	if(argc == 3)
	{
		if(stringToTypeCode(*(argv + 1)) && isNumberString(*(argv + 2)))
		{
			checkRange(*(argv + 1), *(argv + 2));
			// printRange(*(argv + 1));
		}
		else
			printf("Enter a type and a number via the command line (Example int 45)\n");
	}
	else 
	{
		printf("Enter a type and a number via the command line (Example int 45)\n");
	}
	#endif

	#if 0
	
	// Question 2: Arithmatic operations from the command line

	if(argc == 4 && isNumberString(*(argv + 1)) && isNumberString(*(argv + 3)) && getOpcode(*(argv + 2)))
	{
		float a = atof(*(argv + 1));
		float b = atof(*(argv + 3));
		short opCode = getOpcode(*(argv + 2));
		if(opCode == 4 && b == 0.0)
		{
			printf("Divide by zero error\n");
			return 0;
		}
		switch(opCode)
		{
			case 1:
				printf("%f\n", a + b);
				break;
			case 2:
				printf("%f\n", a - b);
				break;
			case 3:
				printf("%f\n", a * b);
				break;
			case 4:
				printf("%f\n", a / b);
				break;
		}
	}
	else
		printf("Invalid Input. Enter the numbers in format: number1 operator number2\n");
	
	#endif

	#if 0
	// Question 3: Arithmatic operations from the command line and QUALIFIERS
	if(argc == 4 && isNumberString(*(argv + 1)) && isNumberString(*(argv + 3)) && getOpcode(*(argv + 2)))
	{
		const float a = atof(*(argv + 1));
		const float b = atof(*(argv + 3));
		volatile short opCode = getOpcode(*(argv + 2));
		if(opCode == 4 && b == 0.0)
		{
			printf("Divide by zero error\n");
			return 0;
		}
		switch(opCode)
		{
			case 1:
				printf("%f\n", a + b);
				break;
			case 2:
				printf("%f\n", a - b);
				break;
			case 3:
				printf("%f\n", a * b);
				break;
			case 4:
				printf("%f\n", a / b);
				break;
		}
	}
	else
		printf("Invalid Input. Enter the numbers in format: number1 operator number2\n");
	#endif

	#if 0
	// Question 4: Display different float formatting
	const float number = 3.14159265;
	printf("Different Formatting of Floating Point Numbers\n");
	printf("%f\n", number);
	printf("%4.3f\n", number);
	printf("%4.8f\n", number);
	printf("%e\n", number);
	printf("%0.2e\n", number);
	printf("%E\n", number);
	#endif

	#if 0
	// Question 5: Addition and Subtraction of Signed Numbers
	
	if(argc == 4 && is8Bit(*(argv + 1)) && isPlusMinus(*(argv + 2)) && is8Bit(*(argv + 3)))
		**(argv + 2) == '+' ? doAddition(*(argv + 1), *(argv + 3)) : doSubtraction(*(argv + 1), *(argv + 3));
	else
		printf("Enter numbers in format: 8bit +/- 8bit\n");
	#endif

	#if 0
	// Question 6: Multiplication of Unsigned Numbers
	
	if(argc == 3 && is8Bit(*(argv + 1)) && is8Bit(*(argv + 2)))
		doMultiplication(*(argv + 1), *(argv + 2));
	else
	#endif
	return 0;
}