concatenate(L1, L2, L):-
  append(L1, L2, L).

q7 :-
  write('Number of items for L1? '),
  read(N),
  length(L1, N),
  maplist(read, L1),
  write('Number of items for L2? '),
  read(N1),
  length(L2, N1),
  maplist(read, L2),
  concatenate(L1, L2, L),
  write('L1= '), write(L1), nl,
  write('L2= '), write(L2), nl,
  write('L= '), write(L).
