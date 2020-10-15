#include <stdio.h>
#include <stdlib.h>

void deleteFromArray();

int main()
{
	deleteFromArray();
	return 0;
}


void deleteFromArray()
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
	// Delete from array
	printf("Enter the positon where to delete: ");
	int position;
	scanf("%d", &position);
	// Assumption: array starts at one
	position--;
	for(int i = position; i < arraySize - 1; i++)
		*(array + i) = *(array + i + 1);
	
	array = (int*)realloc(array, sizeof(int)*(--arraySize));
	//Print Array
	printf("Final Array: ");
	for(int i = 0; i < arraySize; i++)
		printf("%d ", *(array + i));		
	printf("\n");	
}

