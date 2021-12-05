product([], 1).
product([H|T], Product):-
  product(T, Rest),
  Product is H * Rest.
  list_length([], 0 ).

list_length([_|Xs] , L ) :- list_length(Xs,N), L is N+1 .

calc_product(L, Product) :-
  list_length(L, Len),
  (
    Len == 0-> Product is 0;
      product(L, Product)
  ).
