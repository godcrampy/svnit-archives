#include <stdio.h>

#include "types.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yyleng;

int main(int argc, char const* argv[]) {
  int token = yylex();
  int lines = 0, chars = 0, words = 0;

  while (token) {
    switch (token)
    {
    case CARET_RETURN:
      ++lines;
      ++chars;
      break;
    case NON_WHITE_SPACE:
      chars += yyleng;
      ++words;
    case WHITE_SPACE:
      ++chars;
    default:
      break;
    }
    token = yylex();
  }

  printf("Number of lines: %d\n", lines);
  printf("Number of characters: %d\n", chars);
  printf("Number of words: %d\n", words);
  return 0;
}
