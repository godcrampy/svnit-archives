find_n([], _):-write('There is no such element in the list'), nl.

find_n([Element|_], 1) :- write('The element is '), write(Element), nl.

find_n([_|List], N) :-
  N1 is N-1,
  find_n(List, N1).
