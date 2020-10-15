#ifndef UTIL_H
#define UTIL_H 1

int isInRange(int number, int left, int right)
{
	// works
	return left <= number && right >= number;
}

int getYesNo(char *message)
{
	// works
	// keeps asking user of either yes or no and returns the boolean value
	char c = 'a';
	while (1)
	{
		printf("%s", message);
		scanf(" %c", &c);
		getchar(); // To clean the buffer
		if (c == 'y' || c == 'Y' || c == '1')
			return 1;
		if (c == 'n' || c == 'N' || c == '0')
			return 0;
	}
}

char getTaskCode()
{
	// works
	printf("Choose next task\n");
	printf("'i' for Insert\n");
	printf("'s' for Search\n");
	printf("'d' for Delete\n");
	printf("'p' for Print\n");
	printf("'q' for Quitting\n");
	char c = 'a';
	while (1)
	{
		printf("Enter Command: ");
		scanf(" %c", &c);
		getchar(); // To clean the buffer
		if (c == 'i' || c == 'I')
			return 'i';
		if (c == 's' || c == 'S')
			return 's';
		if (c == 'd' || c == 'D')
			return 'd';
		if (c == 'p' || c == 'P')
			return 'p';
		if (c == 'q' || c == 'Q')
			return 'q';
	}
}

char getInsertCode()
{
	// works
	printf("Choose Insert Type\n");
	printf("'f' for Front Insert\n");
	printf("'m' for Middle Insert\n");
	printf("'l' for Last Insert\n");
	char c = 'a';
	while (1)
	{
		printf("Enter Command: ");
		scanf(" %c", &c);
		getchar(); // To clean the buffer
		if (c == 'f' || c == 'F')
			return 'f';
		if (c == 'm' || c == 'M')
			return 'm';
		if (c == 'l' || c == 'L')
			return 'l';
	}
}

char getDeleteCode()
{
	// works
	printf("Choose Delete Type\n");
	printf("'f' for Front Delete\n");
	printf("'m' for Middle Delete\n");
	printf("'l' for Last Delete\n");
	char c = 'a';
	while (1)
	{
		printf("Enter Command: ");
		scanf(" %c", &c);
		getchar(); // To clean the buffer
		if (c == 'f' || c == 'F')
			return 'f';
		if (c == 'm' || c == 'M')
			return 'm';
		if (c == 'l' || c == 'L')
			return 'l';
	}
}

char getSearchCode()
{
	// works
	printf("Choose Search Type\n");
	printf("'n' for Name\n");
	printf("'r' for Roll Number\n");
	printf("'c' for CGPA\n");
	char c = 'a';
	while (1)
	{
		printf("Enter Command: ");
		scanf(" %c", &c);
		getchar(); // To clean the buffer
		if (c == 'n' || c == 'N')
			return 'n';
		if (c == 'r' || c == 'R')
			return 'r';
		if (c == 'c' || c == 'C')
			return 'c';
	}
}

#endif
