%{
  #include "types.h"

%}

%%
\/\/(.*) return SINGLE_LINE_COMMENT;
"/*"([^*]|\*+[^*/])*\*+"/" return MULTI_LINE_COMMENT;
\n return CR;
. return NOT_COMMENT;
%%

int yywrap(void) {return 1;}
