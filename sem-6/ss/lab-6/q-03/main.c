#include <stdio.h>
#include <stdlib.h>

#include "types.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yyleng;

int main(int argc, char const* argv[]) {
  int token = yylex();

  while (token) {
    switch (token) {
      case PHONE:
      printf("Valid Phone\n");
        break;
      case EMAIL:
      printf("Valid Email\n");
        break;
      case NONE:
      printf("Invalid\n");
      default:
        break;
    }
    token = yylex();
  }

  return 0;
}
