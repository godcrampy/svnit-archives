%{
#include <stdio.h>
#include <string.h>
int op = 0, oprs = 0, valid = 1, top = -1, l = 0, j = 0;
char operands[10][10], operators[10][10], stack[100];
%}
%%

"+"|"-"|"*"|"/" {
	op++;
	strcpy(operators[l], yytext);
	l++;
}

[-]?[0-9]+|[a-zA-Z]* {
	oprs++;
	strcpy(operands[j], yytext);
	j++;
}

"(" {
	top++;
	stack[top] = '(';
}

")" {
	if (stack[top] != '(') {
		valid = 0;	
	} else if (oprs > 0 && (oprs - op) != 1) {
		valid = 0;
	} else {
		top--;
		oprs = 1;
		op = 0;
	}
}

"{" {
	top++;
	stack[top] = '{';
}

"}" {
	if (stack[top] != '{') {
		valid = 0;	
	} else if (oprs > 0 && (oprs - op) != 1){
		valid=0;
	} else {
		top--;
		oprs = 1;
		op=0;
	}
}

"[" {
	top++;
	stack[top] = '[';
}

"]" {
	if (stack[top] != '[') {
		valid = 0;
	} else if (oprs > 0 && (oprs - op) != 1){
		valid=0;
	} else {
		top--;
		oprs=1;
		op=0;
	}
		
}

"\n" return 0;
%%


int yywrap(){ return 1; }
int main(){
	int k;
	printf("Enter the arithmetic expression: ");
	yylex();

	if (valid == 1 && top == -1) {
		printf("\nValid Expression!\n");
        printf("\nThe operators are: \n");
        for(int i = 0; i < l; ++i)
            printf("%s ", operators[i]);
        printf("\nThe identifiers are: \n");
        for(int i = 0; i < j; ++i)
            printf("%s ", operands[i]);
        printf("\n");
	}
	else
		printf("\nInvalid Expression!\n");

	return 0;
}