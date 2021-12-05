reverse([], Z, Z).
reverse([H|T], Z, Temp) :- reverse(T, Z, [H|Temp]).
