is_member(X, [H|T]) :-
(
  member(X, [H|T])->
    write('Yes it is a member'), nl;
    write('No, it is not a member'), nl
).
