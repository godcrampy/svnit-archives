min_max_list([A], A, A).

min_max_list([H|R], N, X):-
  min_max_list(R, RN, RX),
  N is min(H, RN),
  X is max(H, RX).
