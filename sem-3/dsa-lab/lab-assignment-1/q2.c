#include <stdio.h>
#include <stdlib.h>

void arraySecondMinMax();

int main()
{
	arraySecondMinMax();
	return 0;
}


void arraySecondMinMax()
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
	// Sort Array
	for(int i = 0; i < arraySize; i++)
	{
		int minLocation = i, min = *(array + i);
		for(int j = i; j < arraySize; j++)
		{
			if(*(array + j) < min)
			{
				min = *(array + j);
				minLocation = j;
			}
		}
	int temp = *(array + i);
	*(array + i) = *(array + minLocation);
	*(array + minLocation) = temp;
	}
	printf("The second smallest number in the array is: %d\n", *(array + 1));	
	printf("The second biggest number in the array is: %d\n", *(array + arraySize - 2));	
}
