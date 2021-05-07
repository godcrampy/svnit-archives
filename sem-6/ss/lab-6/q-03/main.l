%{
  #include "types.h"
%}

%%
[1-9][0-9]{9} return PHONE;
[a-z . 0-9]+@[a-z]+[.][a-z]{2,4} return EMAIL;
.+ return NONE;
%%

int yywrap(void) {return 1;}
