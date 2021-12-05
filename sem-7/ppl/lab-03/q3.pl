odd_even(X) :- (
0 is mod(X, 2)-> write('Even Number'), nl
; write('Odd Number'), nl
).
