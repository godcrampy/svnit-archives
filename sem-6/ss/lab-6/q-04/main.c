#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "types.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yyleng;

int armstrong(char* a) {
  int len = strlen(a), i, num = 0;
  for (i = 0; i < len; i++) num = num * 10 + (a[i] - '0');

  int x = 0, y = 0, temp = num;
  while (num > 0) {
    y = pow((num % 10), len);
    x = x + y;
    num = num / 10;
  }

  return x == temp;
}

int main(int argc, char const* argv[]) {
  int token = yylex();

  while (token) {
    switch (token) {
      case NUMBER:
        if (armstrong(yytext))
          printf("Armstrong\n");
        else
          printf("Not Armstrong\n");
        break;
      case NOT_A_NUM:
        printf("Not a Number\n");
        break;
      default:
        break;
    }
    token = yylex();
  }

  return 0;
}
