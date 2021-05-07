%{
  #include "types.h"
%}

%%
[0-9]* return NUMBER;
.+ return NOT_A_NUM;
%%

int yywrap(void) {return 1;}
