#include <stdio.h>
#include <stdlib.h>

#include "types.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yyleng;

int main(int argc, char const* argv[]) {
  int token = yylex();
  int single = 0, multi = 0;
  FILE* fp = fopen("clean.c", "w");

  while (token) {
    switch (token) {
      case SINGLE_LINE_COMMENT:
        ++single;
        break;
      case MULTI_LINE_COMMENT:
        ++multi;
        break;
      case CR:
        fprintf(fp, "\n");
      case NOT_COMMENT:
        fprintf(fp, "%s", yytext);
      default:
        break;
    }
    token = yylex();
  }
  fclose(fp);
  printf("Number of single line comments: %d\n", single);
  printf("Number of single multi line comments: %d\n", multi);

  return 0;
}
