#include <stdio.h>

void main()
{
	char charac;
	int a ,integer;
	float floating;
	double d;
	
	printf("Enter 1-3 option\n");
	printf("1 for character\n2 for integer\n3 for float\n");
	scanf("%d\n",&a);
	switch(a)
	{
		case 1: 
			scanf("%c",&charac); 
			if (charac>-128 && charac<128) 
				printf("Character is in the range.\n");
			else
				printf("Out of the range\n");
			break;

		case 2: 
			scanf("%d",&integer);
			if(integer>-32768 && integer<32767)
				printf("Integer is in the range.\n");
			else 
				printf("Out of the range\n");
			break;

		case 3: 
			scanf("%f",&floating);
			if(floating>-2147483648 && floating<2147483647)
				printf("Float is in the range.\n");
			else 
				printf("Out of the range\n");	
			break;
		default:
			printf("Invalid Input\n");	
			break;
	}
}
