%{
  #include "types.h"
%}

%%
\n  return CARET_RETURN;
[^ \n\t]+ return NON_WHITE_SPACE;
. return WHITE_SPACE;
%%

int yywrap(void) {return 1;}
