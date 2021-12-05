print_list([]).
print_list([H|T]):-
  write(H),nl,
  print_list(T).

q1:-
  write('Enter number of items? '),
  read(N),
  length(L, N),
  maplist(read, L),
  write('List is: '), nl,
  print_list(L).