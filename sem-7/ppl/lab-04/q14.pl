even_numbers([],[]).
even_numbers([H|T],L1):-
  integer(H),
  (
    H mod 2 =:= 0
    -> L1 = [H|T1], even_numbers(T,T1)
    ; even_numbers(T,L1)
    ).

odd_numbers([],[]).

odd_numbers([H|T],L1):-
  integer(H),
  (
    H mod 2 =:= 1
    -> L1 = [H|T1], odd_numbers(T,T1)
    ; odd_numbers(T,L1)
    ).

split_list:-
  write('Number of items for List? '),
  read(N),
  length(L, N),
  maplist(read, L),
  write('List L= '), write(L), nl,
  even_numbers(L, L1),
  write('Even Number List L1= '), write(L1), nl,
  odd_numbers(L, L2),
  write('Odd Number List L2= '), write(L2), nl.
