#include <stdio.h>
#include <stdlib.h>

void arrayMinMax();

int main()
{
	arrayMinMax();
	return 0;
}


void arrayMinMax()
{
	// Take array
	int arraySize;
	printf("Enter array size: ");
	scanf("%d", &arraySize);
	int* array = (int*)malloc(sizeof(int)*arraySize);
	printf("Enter array elements: ");
	for(int i = 0; i < arraySize; i++)
	{
		scanf("%d", array + i);
	}
	//Find min max
	int minNumber = *(array), maxNumber = *(array);
	for(int i = 0; i < arraySize; i++)
	{
		if(*(array + i) < minNumber)
			minNumber = *(array + i);
		if(*(array + i) > maxNumber)
			maxNumber = *(array + i);
	}
	printf("The smallest number in the array is: %d\n", minNumber);	
	printf("The biggest number in the array is: %d\n", maxNumber);	
}

