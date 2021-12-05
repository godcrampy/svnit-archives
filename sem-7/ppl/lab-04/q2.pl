sum_list([], 0).
sum_list([H|T], Sum) :-
  sum_list(T, Rest),
  Sum is H + Rest.
