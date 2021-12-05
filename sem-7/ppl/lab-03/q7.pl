solve(A,B,C) :- D is B*B - 4*A*C, reply(A,B,D), nl.
reply(A, B, D) :-
((D < 0)
-> write('Imaginary Root'), nl
; (D == 0) -> ANS is -B / (2 * A), write('Equal Roots X= '), write(ANS), nl
; X1 is (-B + sqrt(D)) / (2 * A), X2 is (-B - sqrt(D)) / (2 * A),
write('R1: '), write(X1), nl, write('R2: '), write(X2), nl
).
