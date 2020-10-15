#include <stdio.h>
#include <stdlib.h>

float stringToFloat(char **a);

int main(int argc, char **argv)
{
	if(argc < 3)
	{
		printf("%s\n", "error: Please provide two numbers" );
		return 1;
	}
	float a = stringToFloat(argv + 1);
	float b = stringToFloat(argv + 2);
	if(b == 0)
	{
		printf("%s\n", "error: Please provide non zero denominator");
		return 1;
	}
	printf("%f\n", a/b);
	return 0;
}

float stringToFloat(char **a)
{
	return atoi(*a);
}