#include <stdio.h>
#include <stdlib.h>

void insertInArray();

int main()
{
	insertInArray();
	return 0;
}


void insertInArray()
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
	// Insert into array
	printf("Enter the number to be inserted: ");
	int data;
	scanf("%d", &data);	
	printf("Enter the positon where to insert: ");
	int position;
	scanf("%d", &position);
	// Assumption: array starts at one
	position--;
	array = (int*)realloc(array, sizeof(int)*(++arraySize));
	for(int i = arraySize - 1; i > position; i--)
		*(array + i) = *(array + i - 1);
	
	printf("Final Array: ");
	*(array + position) = data;
	//Print Array
	for(int i = 0; i < arraySize; i++)
		printf("%d ", *(array + i));
	printf("\n");	
}
