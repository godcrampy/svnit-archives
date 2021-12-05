sort_list(List, Sorted) :- sort_util(List,[], Sorted).

sort_util([], Acc, Acc).

sort_util([H|T], Acc, Sorted) :- swap_elements(H, T, NT, Max), sort_util(NT, [Max|Acc], Sorted).

swap_elements(X, [], [], X).

swap_elements(X, [Y|T], [Y|NT], Max) :- X > Y, swap_elements(X, T, NT, Max).

swap_elements(X, [Y|T], [X|NT], Max) :- X =< Y, swap_elements(Y, T, NT, Max).

merge_and_sort(L1, L2, List, Sorted) :-
  append(L1, L2, List),
  sort_list(List, Sorted).
