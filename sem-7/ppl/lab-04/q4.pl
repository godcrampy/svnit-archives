vowel(X):- member(X,[a,e,i,o,u]).

vowel_count([], 0).
vowel_count([X|T], N):-
  vowel(X),
  vowel_count(T,N1),
  N is N1+1.

vowel_count([_|T], N):- vowel_count(T, N).

q4 :-
  write('Enter number of items in a list: '),
  read(N),
  length(L, N),
  maplist(read, L),
  vowel_count(L, T),
  write('Number of vowels in string is: '), write(T).