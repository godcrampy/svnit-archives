#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char** argv)
{
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
	return 0;
}