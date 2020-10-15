#ifndef EXPRESSION
#define EXPRESSION

#include <stdlib.h>
#include <stdio.h>

int lengthOfString(char *string)
{
	// works
	int count = 0;
	while (*(string + count) != '\0')
		++count;
	return count;
}

char *newString(int size)
{
	// works
	// Returns a string of given length all charecters '0'
	char *final = (char *)malloc(sizeof(char) * size);
	for (int i = 0; i < size; i++)
		*(final + i) = ' ';
	return final;
}

char *copyString(char *string)
{
	// works
	// returns a copy of the given string
	int length = lengthOfString(string);
	char *copy = (char *)malloc(sizeof(char) * (length));
	for (int i = 0; i < length; i++)
		*(copy + i) = *(string + i);
	return copy;
}

char *deleteAtIndex(char *string, int index)
{
	// works
	// deletes a charecter at the given index and return a new string
	int length = lengthOfString(string);
	char *copy = (char *)malloc(sizeof(char) * (length - 1));
	for (int i = 0; i < index; i++)
		*(copy + i) = *(string + i);
	for (int i = index; i < length - 1; i++)
		*(copy + i) = *(string + i + 1);
	return copy;
}

char *cleanExpression(char *expression)
{
	// works
	// removes any spaces in the expression
	int length = lengthOfString(expression);
	char *copy = copyString(expression);
	for (int i = 0; i < length; i++)
	{
		if (*(copy + i) == ' ')
			copy = deleteAtIndex(copy, i);
	}
	return copy;
}

int isBracket(char charecter)
{
	// works
	// returns true if given charecter is a bracket
	return charecter == '{' || charecter == '[' || charecter == '(' || charecter == '}' || charecter == ']' || charecter == ')' ? 1 : 0;
}

int isOpeningBracket(char charecter)
{
	// works
	return charecter == '{' || charecter == '[' || charecter == '(' ? 1 : 0;
}

int areBracketsPaired(char opening, char closing)
{
	// works
	if ((opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']'))
		return 1;
	return 0;
}

int isOperator(char charecter)
{
	// works
	return charecter == '+' || charecter == '-' || charecter == '*' || charecter == '/' || charecter == '^' ? 1 : 0;
}

char *returnSpace()
{
	// works
	char *space = (char *)malloc(sizeof(char));
	*space = ' ';
	return space;
}

int charToInt(char charecter)
{
	// works
	return charecter - '0';
}

char intToChar(int integer)
{
	// works
	return integer + '0';
}

int power(int a, int b)
{
	// works
	int result = 1;
	for (int i = 0; i < b; i++)
		result *= a;
	return result;
}

// char intToChar

int computeOperation(char operation, char number1, char number2)
{
	// works
	if (operation == '^')
		return power(charToInt(number1), charToInt(number2));
	if (operation == '+')
		return charToInt(number1) + charToInt(number2);
	if (operation == '-')
		return charToInt(number1) - charToInt(number2);
	if (operation == '*')
		return charToInt(number1) * charToInt(number2);
	if (operation == '/')
		return charToInt(number1) / charToInt(number2);
	return -1;
}

int getOperatorWeight(char charecter)
{
	// higher priority higher weight. If not an operator returns -1
	if (charecter == '*' || charecter == '/')
		return 2;
	else if (charecter == '+' || charecter == '-')
		return 1;
	else if (charecter == '^')
		return 3;
	return -1;
}

int isFirstOperatorMoreOrEquallyImportant(char operator1, char operator2)
{
	// works
	return getOperatorWeight(operator1) >= getOperatorWeight(operator2);
}

int isFirstOperatorMoreImportant(char operator1, char operator2)
{
	return getOperatorWeight(operator1) > getOperatorWeight(operator2);
}

char *infixToPostfix(char *expression)
{
	// works
	char *infix = cleanExpression(expression);
	int length = lengthOfString(infix);
	char *postfix = newString(length);
	char *stack = newString(length);
	int stackEmptyPosition = 0, postfixEmptyPostion = 0;
	for (int i = 0; i < length; i++)
	{
		// i is the iterator for infix
		if (isBracket(*(infix + i)))
		{
			// brackets
			if (isOpeningBracket(*(infix + i)))
			{
				// opening bracket
				*(stack + stackEmptyPosition) = *(infix + i);
				stackEmptyPosition++;
			}
			else
			{
				// closing bracket
				while ((!isBracket(*(stack + stackEmptyPosition - 1))) && stackEmptyPosition > 0)
				{
					*(postfix + postfixEmptyPostion) = *(stack + stackEmptyPosition - 1);
					--stackEmptyPosition;
					++postfixEmptyPostion;
				}
				if (stackEmptyPosition == -1)
				{
					printf("%s\n", "Stack Position 0");
					printf("%s\n", "No matching bracket found");
					return returnSpace();
				}
				else
				{
					// found a bracket
					if (areBracketsPaired(*(stack + stackEmptyPosition - 1), *(infix + i)))
					{
						--stackEmptyPosition;
					}
					else
					{
						printf("Brackets not paired\n");
						printf("%s\n", "No matching bracket found");
						return returnSpace();
					}
				}
			}
		}
		else if (isOperator(*(infix + i)))
		{
			// operator
			// *(stack + stackEmptyPosition) = *(infix + i);
			// ++stackEmptyPosition;
			if (stackEmptyPosition == 0 || isFirstOperatorMoreImportant(*(infix + i), *(stack + stackEmptyPosition - 1)))
			{
				// stack has either an operator with lower value or bracket or is empty. Push the operator
				*(stack + stackEmptyPosition) = *(infix + i);
				++stackEmptyPosition;
			}
			else
			{
				// pop all the operators that are greater or equal to the current operator. Push the operator then
				while (stackEmptyPosition != 0 && isFirstOperatorMoreOrEquallyImportant(*(stack + stackEmptyPosition - 1), *(infix + i)))
				{
					*(postfix + postfixEmptyPostion) = *(stack + stackEmptyPosition - 1);
					++postfixEmptyPostion;
					--stackEmptyPosition;
				}
				*(stack + stackEmptyPosition) = *(infix + i);
				++stackEmptyPosition;
			}
		}
		else
		{
			// is variable
			*(postfix + postfixEmptyPostion) = *(infix + i);
			++postfixEmptyPostion;
		}
	}
	// copy the rest of the stack
	while (stackEmptyPosition != 0)
	{
		if (isOpeningBracket(*(stack + stackEmptyPosition - 1)))
		{
			printf("Opening Bracket in Stack\n");
			return returnSpace();
		}
		*(postfix + postfixEmptyPostion) = *(stack + stackEmptyPosition - 1);
		++postfixEmptyPostion;
		--stackEmptyPosition;
	}
	return postfix;
}

int evaluatePostfix(char *postfix)
{
	//works
	int length = lengthOfString(postfix);
	char *stack = newString(length);
	int stackEmptyPosition = 0;
	for (int i = 0; i < length; i++)
	{
		if (isOperator(*(postfix + i)))
		{
			*(stack + stackEmptyPosition - 2) = intToChar(computeOperation(*(postfix + i), *(stack + stackEmptyPosition - 2), *(stack + stackEmptyPosition - 1)));
			--stackEmptyPosition;
		}
		else
		{
			// is number
			*(stack + stackEmptyPosition) = *(postfix + i);
			++stackEmptyPosition;
		}
	}
	return charToInt(*stack);
}

#endif