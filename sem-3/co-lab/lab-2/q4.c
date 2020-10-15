#include <stdio.h>

int main(int argc, char** argv)
{
	const float number = 3.14159265;
	printf("Different Formatting of Floating Point Numbers\n");
	printf("%f\n", number);
	printf("%4.3f\n", number);
	printf("%4.8f\n", number);
	printf("%e\n", number);
	printf("%0.2e\n", number);
	printf("%E\n", number);
	return 0;
}