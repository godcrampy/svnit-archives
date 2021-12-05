list_length([], 0 ).

list_length([_|Xs] , L ) :- list_length(Xs,N), L is N+1 .
