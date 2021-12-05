palindrome([]).
palindrome([_]).
palindrome(Pal) :-
  append([H|T], [H], Pal),
  palindrome(T).

is_palindrome(L) :-
(
  palindrome(L) -> write('Yes, the list is palindrome'), nl;
    write('No, the list is not palindrome'), nl
).
